MDLowpassFirstOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq).madd(mul, add);
	}

}

MDLowpassSecondOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}

MDHighpassFirstOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq).madd(mul, add);
	}

}

MDHighpassSecondOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}

MDLowshelfFirstOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, gain).madd(mul, add);
	}

}

MDLowshelfSecondOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}

MDHighshelfFirstOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, gain).madd(mul, add);
	}

}

MDHighshelfSecondOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}

MDTiltFirstOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, gain).madd(mul, add);
	}

}

MDTiltSecondOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, gain = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r, gain).madd(mul, add);
	}

}

MDBandpass : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}

MDAllpassFirstOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq).madd(mul, add);
	}

}

MDAllpassSecondOrder : Filter {

	*ar { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, freq, r).madd(mul, add);
	}

	*kr { arg in = 0.0, freq = 440.0, r = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, freq, r).madd(mul, add);
	}

}
