/**
 * White Chorus effect as described in "Effect Design - Part 2: Delay-Line modulation
 * and Chorus" by Jon Dattorro, J. Audio Eng Soc., Vol 45, No. 10, 1997 October.
 */
Chorus {

	*ar { arg input, rate = 0.01, depth = 0.9, delayTime = 0.1;
		var numChannels, feedback, phase, delayed;

		numChannels = input.numChannels;

		feedback = LocalIn.ar(numChannels);
		input = (numChannels === 1).if { [input] } { input } - feedback;

		phase = Phasor.ar(0, rate * 2pi * SampleDur.ir, 0, 2pi);
		delayed = numChannels collect: { |i|
			TapDelay.ar(input[i], delayTime * 2, [
				delayTime, SinOsc.ar(0, 0.5pi * i + phase, delayTime, delayTime)
			], 4);
		};

		LocalOut.ar((delayed collect: _.first) * 0.7071);

		^(input * 0.7071 + (delayed collect: _.last));
	}

}