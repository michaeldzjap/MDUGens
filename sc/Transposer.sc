/**
 * Delay based pitch shifter.
 *
 * Parameters:
 * input - The N-channel input signal for the pitch shifter
 * transposition - Transposition factor
 * dur - The size / length of the window in seconds
 * overlap - The number of windows that will overlap
 */
Transposer {

	*ar { arg input, transposition = 0, dur = 0.12, maxDelayTime = 1, overlap = 2;
		var freq, phase, window, output;

		freq = (transposition.midiratio - 1) * -1 * dur.reciprocal;
		phase = { |i|
			(Phasor.ar(0, freq * SampleDur.ir, 0, 1) + (i * overlap.reciprocal)).wrap(0, 1)
		} ! overlap;
		window = SinOsc.ar(0, phase * 2pi - 0.5pi, 0.5, 0.5);

		output = (input.numChannels > 1).if {
			input collect: { |in| DelayC.ar(in, maxDelayTime, phase * dur, window).sum }
		} {
			DelayC.ar(input, maxDelayTime, phase * dur, window).sum
		};

		^(2 * overlap.reciprocal * output);
	}

}