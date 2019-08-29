GaussianNoise {

	*ar { arg mean = 0, variance = 1, mul = 1, add = 0;
		var x = sqrt(-2 * log(WhiteNoise.ar(0.5, 0.5))) * cos(2pi * WhiteNoise.ar(0.5, 0.5));
		^(sqrt(variance) * x + mean)
	}

}