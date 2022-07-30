ReverseDelay : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, overlap = 2, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, overlap).madd(mul, add);
	}

}

/*ReversibleDelay : PureUGen {

	*ar { arg in = 0.0, maxdelaytime = 0.2, delaytime = 0.2, reversed = false, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in.asAudioRateInput, maxdelaytime, delaytime, reversed).madd(mul, add);
	}

}*/
