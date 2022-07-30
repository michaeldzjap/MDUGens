MD_WhiteNoise : PureUGen {

	*ar { arg mul = 1.0, add = 0.0;
		^this.multiNew('audio').madd(mul, add);
	}

	*kr { arg mul = 1.0, add = 0.0;
		^this.multiNew('control').madd(mul, add);
	}

}
