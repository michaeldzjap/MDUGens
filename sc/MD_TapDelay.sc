MD_TapDelay : MultiOutUGen {

	*ar { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2, interpolation = 0;
		^this.multiNew('audio', taps, in.asAudioRateInput, bufnum, maxdelaytime, interpolation);
	}

	*kr { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2, interpolation = 0;
		^this.multiNew('control', taps, in, bufnum, maxdelaytime, interpolation);
	}

	init { arg taps ... theInputs;
		inputs = theInputs;

		^this.initOutputs(taps, rate);
	}

	checkInputs { ^this.checkNInputs(1) }

	argNamesInputsOffset { ^2 }

}

MD_TapDelayStatic : MultiOutUGen {

	*ar { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2;
		^this.multiNew('audio', taps, in.asAudioRateInput, bufnum, maxdelaytime);
	}

	*kr { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2;
		^this.multiNew('control', taps, in, bufnum, maxdelaytime);
	}

	init { arg taps ... theInputs;
		inputs = theInputs;

		^this.initOutputs(taps, rate);
	}

	checkInputs { ^this.checkNInputs(1) }

	argNamesInputsOffset { ^2 }

}

MD_TapDelayLinear : MultiOutUGen {

	*ar { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2;
		^this.multiNew('audio', taps, in.asAudioRateInput, bufnum, maxdelaytime);
	}

	*kr { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2;
		^this.multiNew('control', taps, in, bufnum, maxdelaytime);
	}

	init { arg taps ... theInputs;
		inputs = theInputs;

		^this.initOutputs(taps, rate);
	}

	checkInputs { ^this.checkNInputs(1) }

	argNamesInputsOffset { ^2 }

}

MD_TapDelayCubic : MultiOutUGen {

	*ar { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2;
		^this.multiNew('audio', taps, in.asAudioRateInput, bufnum, maxdelaytime);
	}

	*kr { arg taps, in = 0.0, bufnum = 0, maxdelaytime = 0.2;
		^this.multiNew('control', taps, in, bufnum, maxdelaytime);
	}

	init { arg taps ... theInputs;
		inputs = theInputs;

		^this.initOutputs(taps, rate);
	}

	checkInputs { ^this.checkNInputs(1) }

	argNamesInputsOffset { ^2 }

}
