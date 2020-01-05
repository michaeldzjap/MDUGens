/**
 * Delay based input reverser ported to SuperCollider from Pure Data (Pierre Guillot's
 * delback~). Works "best" with longer buffer sizes, but interesting results can be
 * obtained with shorter times.
 *
 * Parameters:
 * input - The N-channel input signal for the delay line
 * dur - The size / length of the window (i.e. reversed segment) in seconds
 * maxDelayTime - The maximum delay time of the delay line buffer
 * overlap - The number of windows that will overlap
 */
Reverser {

	*ar { arg input, dur = 0.5, maxDelayTime = 1, overlap = 2;
		var freq, phase, window, blockDur, output;

		dur = dur.clip(BlockSize.ir.reciprocal, maxDelayTime);

		freq = dur.reciprocal * 2;
		phase = { |i|
			(Phasor.ar(0, freq * SampleDur.ir, 0, 1) + (i * overlap.reciprocal)).wrap(0, 1)
		} ! overlap;
		window = SinOsc.ar(0, phase * 2pi - 0.5pi, 0.5, 0.5);

		output = (input.numChannels > 1).if {
			input collect: { |ip|
				DelayC.ar(ip, maxDelayTime, phase * dur, window).sum;
			}
		} {
			DelayC.ar(input, maxDelayTime, phase * dur, window).sum;
		};

		^(2 * overlap.reciprocal * output);
	}

}