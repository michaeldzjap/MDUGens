MD_AllpassStatic : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime, gain).madd(mul, add);
	}

}

MD_AllpassLinear : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime, gain).madd(mul, add);
	}

}

MD_AllpassCubic : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, gain).madd(mul, add);
	}

	*kr { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, gain = 0.2, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, maxdelaytime, delaytime, gain).madd(mul, add);
	}

}
