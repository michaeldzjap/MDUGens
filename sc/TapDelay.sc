TapDelay {

	*ar { arg input, maxDelayTime = 0.2, delayTimes = [0.2], interpolation = 1;
		var numChannels, buffer, length, phase;

		numChannels = input.numChannels;
		buffer = LocalBuf(maxDelayTime * SampleRate.ir + BlockSize.ir, numChannels).clear;
		length = BufFrames.ir(buffer);
		phase = Phasor.ar(0, 1, 0, length);

		BufWr.ar(input, buffer, phase);

		^(delayTimes.min(maxDelayTime) collect: { |delayTime|
			BufRd.ar(numChannels, buffer, (phase - (delayTime * SampleRate.ir)).wrap(0, length), 1, interpolation)
		});
	}

}