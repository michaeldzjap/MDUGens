/**
 * Eliminate clicks that result from changing the delay time abruptly by crossfading
 * between different taps and applying a window function to the output of each tap.
 *
 * Parameters:
 * input - The N-channel input signal to the delay line
 * maxDelayTime - The maximum delay time of the delay line buffer
 * delayTime - Time (seconds) by whichthe input signal will be delayed
 * dur - The size / length of the window in seconds
 * overlap - The number of windows that will overlap
 */
VariableDelay {

	*ar { arg input, maxDelayTime = 0.2, delayTime = 0.2, dur = 0.2, overlap = 2;
		var trig, phase, window, output, rate = dur.reciprocal;

		trig = Impulse.ar(rate, { |i| i * overlap.reciprocal} ! overlap);
		phase = Phasor.ar(trig, rate * 2pi * SampleDur.ir, 0, 2pi);
		window = SinOsc.ar(0, phase - 0.5pi, 0.5, 0.5);

		delayTime = Latch.ar(delayTime, trig);
		output = TapDelay.ar(input, maxDelayTime, delayTime, 1);

		(input.numChannels > 1).if {
			^(output.flop collect: { |o| (o * window).sum });
		} {
			^(output * window).sum;
		}
	}

}