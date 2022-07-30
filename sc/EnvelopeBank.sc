EnvelopeBank {
	classvar <maxLevels = 20;

	*ar { arg trig, env, minDelay, maxDelay, gain = 1, voices = 10;
		env = env.clump(maxLevels * 4);
		trig = TDelay.ar(trig, TRand.ar(minDelay, maxDelay, trig));


		^({ |i| EnvGen.ar(env[i], trig[i], gain) } ! voices);
	}

	*parseDelay { arg value, voices;
		value.isSequenceableCollection.if {
			(value.size < voices).if {
				^(value ++ ((voices - value.size) collect: { |i| value.wrapAt(i) }));
			};

			(value.size > voices).if {
				^value[0..voices - 1];
			};

			^value;
		};

		^(value ! voices);
	}

	*parseEnv { arg value, voices;
		value.isKindOf(Env).if {
			^(EnvelopeBank.prCheckEnvLength(value).asArray ! voices).flatten;
		};

		value.isSequenceableCollection.if {
			var envs = value collect: { |e|
				e.isKindOf(Env).if {
					EnvelopeBank.prCheckEnvLength(e).asArray;
				} {
					e.isSequenceableCollection.if {
						e; // Assume the envelope has already been transformed to an array
					} {
						"The env argument is invalid.".throw;
					}
				}
			};

			(envs.size < voices).if {
				^(envs ++ ((voices - envs.size) collect: { |i| envs.wrapAt(i) }));
			};

			(envs.size > voices).if {
				^envs[0..voices - 1];
			};

			^envs.flatten;
		};


		"The env argument is invalid.".throw;
	}

	*prCheckEnvLength { arg e;
		(e.levels.size < maxLevels).if {
			var zeros = 0 ! (maxLevels - e.levels.size);

			^Env(
				e.levels ++ zeros,
				e.times ++ zeros,
				e.curves.isSequenceableCollection.if { e.curves ++ zeros } { e.curves },
				e.releaseNode,
				e.loopNode,
				e.offset
			);
		};

		(e.levels.size > maxLevels).if {
			^Env(
				e.levels[0..maxLevels - 1],
				e.times[0..maxLevels - 2],
				e.curves.isSequenceableCollection.if { e.curves[0..maxLevels - 2]} { e.curves },
				e.releaseNode,
				e.loopNode,
				e.offset
			);
		};

		^e;
	}

}