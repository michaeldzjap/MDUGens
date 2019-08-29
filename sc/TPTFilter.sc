TPTLowpass : Filter {

	*ar { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq).madd(mul, add);
	}

}

TPTHighpass : Filter {

	*ar { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq).madd(mul, add);
	}

}

TPTAllpass : Filter {

	*ar { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq).madd(mul, add);
	}

}

TPTLowshelf : Filter {

	*ar { arg in = 0.0, freq = 440.0, gain = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, gain = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, gain).madd(mul, add);
	}

}

TPTHighshelf : Filter {

	*ar { arg in = 0.0, freq = 440.0, gain = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, gain = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, gain).madd(mul, add);
	}

}

TPTTilt : Filter {

	*ar { arg in = 0.0, freq = 440.0, gain = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, gain = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, gain).madd(mul, add);
	}

}

TPTSVF : MultiOutUGen {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

	init { |... theInputs|
        inputs = theInputs;
        ^this.initOutputs(3, rate);
    }

}

TPTLowpass2 : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}

TPTHighpass2 : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}

TPTBandpass : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}

TPTBandstop : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}

TPTLowshelf2 : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}

TPTHighshelf2 : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}

TPTBandshelf : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}

TPTTilt2 : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}

TPTAllpass2 : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}
