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

// MD_ReverseDelay : PureUGen {
//
// 	*ar { arg in = 0.0, maxdelaytime = 1.0, size = 0.5, overlap = 2, mul = 1.0, add = 0.0;
// 		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, size, overlap).madd(mul, add);
// 	}
//
// }
//
// MD_ReversibleDelay : PureUGen {
//
// 	*ar { arg in = 0.0, maxdelaytime = 1.0, size = 0.5, reversed = 0.0, overlap = 2, mul = 1.0, add = 0.0;
// 		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, size, reversed, overlap).madd(mul, add);
// 	}
//
// }
//
// MD_PitchShifter : PureUGen {
//
// 	*ar { arg in = 0.0, maxdelaytime = 1.0, size = 0.5, transposition = 0.0, overlap = 2, mul = 1.0, add = 0.0;
// 		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, size, transposition, overlap).madd(mul, add);
// 	}
//
// }
//
// MD_VariableDelay : PureUGen {
//
// 	*ar { arg in = 0.0, maxdelaytime = 1.0, delaytime = 0.5, size = 0.2, overlap = 2, mul = 1.0, add = 0.0;
// 		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, size, overlap).madd(mul, add);
// 	}
//
// }
