Phaser1 {

	*ar { arg input, depth = 0.5, rate = 1, fb = 0.3, cfb = 0.1, rot = 0.5pi;
		var output, lfo, feedback, ac;

		// compute allpass coefficient
		ac = { |freq|
			var theta = pi * SampleDur.ir * freq;
			var a1 = (1 - tan(theta)) / (1 + tan(theta));
			a1;
		};

		lfo = [0, rot] collect: { |w| SinOsc.ar(rate, w).range(0, 1) };
		feedback = LocalIn.ar(2);
		output = input + (feedback * fb) + (feedback.reverse * cfb);
		[[16, 1600], [33, 3300], [48, 4800], [98, 9800], [160, 16000], [260, 22050]] do: { |freqs|
			var a1 = ac.(freqs[0] + ((freqs[1] - freqs[0]) * lfo));
			output = FOS.ar(output, a1, -1, a1);   // 1st order allpass
		};
		output = depth * output;
		LocalOut.ar(output);

		^((1 - depth) * input + output);
	}

}

Phaser2 {

	*ar { arg input, depth = 0.5, rate = 1, fb = 0.3, cfb = 0.1, rot = 0.5pi, rq = 1;
		var output, lfo, feedback, ac;

		// compute allpass coefficient
		ac = { |freq, rq|
			var a2 = 1 - (pi * (freq/SampleRate.ir) * rq);
			var a1 = -2 * a2 * cos(freq * 2pi * SampleDur.ir);
			a2 = a2.squared;
			[a1, a2];
		};

		lfo = [0, rot] collect: { |w| SinOsc.ar(rate, w).range(0, 1) };
		feedback = LocalIn.ar(2);
		output = input + (feedback * fb) + (feedback.reverse * cfb);
		[[16, 1600], [33, 3300], [48, 4800], [98, 9800], [160, 16000], [260, 22050]] do: { |freqs|
			var a1, a2;
			#a1, a2 = ac.(freqs[0] + ((freqs[1] - freqs[0]) * lfo), rq);
			// smooth time-varying coeffs with a 1-pole lowpass (doesn't seem like we need it though...)
			//#a1, a2 = [a1, a2] collect: { |c| FOS.ar(c, 1 - 0.997, 0, 0.997) };
			output = SOS.ar(output, a2, a1, 1, a1.neg, a2.neg);
		};
		output = depth * output;
		LocalOut.ar(output);

		^((1 - depth) * input + output);
	}

}