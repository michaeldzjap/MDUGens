MD_Phasor : PureUGen {

	*ar { arg frequency = 1.0, phase = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', frequency, phase).madd(mul, add);
	}

	*kr { arg frequency = 1.0, phase = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', frequency, phase).madd(mul, add);
	}

}

MD_HannOscillator : PureUGen {

	*ar { arg frequency = 1.0, phase = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', frequency, phase).madd(mul, add);
	}

	*kr { arg frequency = 1.0, phase = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', frequency, phase).madd(mul, add);
	}

}

MD_SineOscillator : PureUGen {

	*ar { arg frequency = 440.0, phase = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('audio', frequency, phase).madd(mul, add);
	}

	*kr { arg frequency = 1.0, phase = 0.0, mul = 1.0, add = 0.0;
		^this.multiNew('control', frequency, phase).madd(mul, add);
	}

}
