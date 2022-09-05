MDDelayStatic : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime).madd(mul, add);
	}

}

MDDelayLinear : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime).madd(mul, add);
	}

}

MDDelayCubic : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime).madd(mul, add);
	}

}

MDAllpassStatic : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime, gain).madd(mul, add);
	}

}

MDAllpassLinear : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime, gain).madd(mul, add);
	}

}

MDAllpassCubic : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime, gain).madd(mul, add);
	}

}


MDReverseDelay : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 1.0, size = 0.5, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, size).madd(mul, add);
	}

}


MDPitchShifter : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 1.0, size = 0.5, transposition = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, size, transposition).madd(mul, add);
	}

}

MDVariableDelay : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 1.0, delaytime = 0.5, size = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, size).madd(mul, add);
	}

}
