SOSBank : MultiOutUGen {

	*ar { arg numInputs, numOutputs, in = 0.0, bufnum_a0 = -1, bufnum_a1 = -1, bufnum_a2 = -1, bufnum_b1 = -1, bufnum_b2 = -1, mul = 1.0, add = 0.0;
		^this.multiNew('audio', numInputs, numOutputs, in, bufnum_a0, bufnum_a1, bufnum_a2, bufnum_b1, bufnum_b2).madd(mul, add)
	}

	init { arg numInputs, numOutputs ... theInputs;
		inputs = theInputs;
		^this.initOutputs(numInputs*numOutputs, rate)
	}
	argNamesInputsOffset { ^3 }

}