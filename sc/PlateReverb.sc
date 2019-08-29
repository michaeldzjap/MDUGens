/**
 * A SuperCollider port of the yafr2 reverb patch found in the Max/MSP examples folder.
 *
 * Ported to SuperCollider by Michael Dzjaparidze 2017.
 */

PlateReverb {

	*ar { arg input, size = 0.8, decayTime = 0.5, damping = 0.6, diffusion = 1.0;
		var output, allpass, comb, allpass2, delay, calcDecayTime, scaledSize, scaledDecayTime, scaledDiffusion, feedback;

		calcDecayTime = { arg delayTime, gain;
			          // log(0.001)
			delayTime*6.9077552789821.neg*log(gain).reciprocal;
		};

		output = OnePole.ar(input, damping);
		[
			[0.01, 0.00476, 0.75], [0.01, 0.00358, 0.75], [0.02, 0.01273, 0.625], [0.01, 0.0093, 0.625]
		] do: { |a| output = AllpassN.ar(output, a[0], a[1], calcDecayTime.(a[1], a[2])) };

		scaledSize = size.linlin(0.0, 1.0, 0.01, 1.6);
		scaledDecayTime = decayTime.linlin(0.0, 1.0, 0.05, 0.9);

		feedback = LocalIn.ar(2);

		allpass = [0.02258, 0.03051] collect: { |c, i|
			AllpassN.ar(output + feedback[i], 0.05, scaledSize*c, calcDecayTime.(scaledSize*c, 0.7));
		};

		comb = [0.1496, 0.1417] collect: { |c, i|
			DelayC.ar(allpass[i], 1.0, scaledSize*c + LFNoise2.ar(10, 5e-4))
		};

		allpass2 = [0.06048, 0.08924] collect: { |c, i|
			var signal = OnePole.ar(comb[i], damping, scaledDecayTime);
			AllpassN.ar(signal, 0.2, scaledSize*c, calcDecayTime.(scaledSize*c, 0.5));
		};

		delay = [0.125, 0.10628] collect: { |c, i|
			DelayN.ar(allpass2[i], 1.0, scaledSize*c)
		};

		LocalOut.ar(delay);

		scaledDiffusion = diffusion*scaledSize;
		output = [[0.11, 0.16, 0.05, 0.025, 0.069, 0.08, 0.075], [0.11, 0.135, 0.055, 0.003, 0.035, 0.027, 0.052]] collect: { |c, i|
			var signal = DelayN.ar(allpass[i], 0.3, c[0]*scaledDiffusion) + DelayN.ar(allpass[i], 0.3, c[1]*scaledDiffusion) + DelayN.ar(delay[i], 0.1, c[3]*scaledDiffusion);
			signal = signal - (DelayN.ar(allpass2[i], 0.2, c[2]*scaledDiffusion, -1) + DelayN.ar(comb[(i + 1) % 2], 0.2, c[4]*scaledDiffusion, -1) + DelayN.ar(allpass2[(i + 1) % 2], 0.2, c[5]*scaledDiffusion, -1) + DelayN.ar(delay[(i + 1) % 2], 0.2, c[6]*scaledDiffusion, -1));
			0.15*signal;
		};

		^output;
	}

}