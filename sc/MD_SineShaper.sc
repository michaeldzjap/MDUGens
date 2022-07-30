MD_SineShaper : PureUGen {

	*ar { arg in = 0.0, limit = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, limit).madd(mul, add);
	}

	*kr { arg in = 0.0, limit = 1.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, limit).madd(mul, add);
	}

}
