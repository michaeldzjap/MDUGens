EnvelopeBankPresets {

	*load { arg preset ... args;
		^EnvelopeBankPresets.perform(EnvelopeBankPresets.prFormatMethodName(preset), *args);
	}

	*prPeriodicGrains { arg dur = 0.02, delay = 0.02, voices, overrides = [];
		(overrides.includes(\maxDelay) or: { overrides.includes(\minDelay) }).not.if {
			var d = { delay.rand } ! voices;

			overrides = overrides.add(\minDelay).add(d);
			overrides = overrides.add(\maxDelay).add(d);
		};

		overrides.includes(\env).not.if {
			overrides = overrides.add(\env).add(
				EnvelopeBank.parseEnv(Env.sine(dur), voices)
			);
		};

		^overrides;
	}

	*prRandomGrains { arg dur = 0.02, minDelay = 0.02, maxDelay = 0.05, voices, overrides = [];
		overrides.includes(\minDelay).not.if {
			overrides = overrides.add(\minDelay).add({ minDelay.rand } ! voices);
		};

		overrides.includes(\maxDelay).not.if {
			overrides = overrides.add(\maxDelay).add({ minDelay + maxDelay.rand } ! voices);
		};

		overrides.includes(\env).not.if {
			overrides = overrides.add(\env).add(
				EnvelopeBank.parseEnv(Env.sine(dur), voices)
			);
		};

		^overrides;
	}

	*prLongSine { arg dur = 12, voices, overrides = [];
		(overrides.includes(\maxDelay) or: { overrides.includes(\minDelay) }).not.if {
			var delay = { |i| rrand(0.25 * i, 3 * i).round(0.25) } ! voices;

			overrides = overrides.add(\minDelay).add(delay);
			overrides = overrides.add(\maxDelay).add(delay);
		};

		overrides.includes(\env).not.if {
			overrides = overrides.add(\env).add(
				EnvelopeBank.parseEnv(Env.sine(dur), voices)
			);
		};

		^overrides;
	}

	*prLongDecay { arg dur = 12, voices, overrides = [];
		(overrides.includes(\maxDelay) or: { overrides.includes(\minDelay) }).not.if {
			var delay = { |i| rrand(0.25 * i, 3 * i).round(0.25) } ! voices;

			overrides = overrides.add(\minDelay).add(delay);
			overrides = overrides.add(\maxDelay).add(delay);
		};

		overrides.includes(\env).not.if {
			overrides = overrides.add(\env).add(
				EnvelopeBank.parseEnv(Env([0, 1, 0], [0.001, dur - 0.001], -3), voices)
			);
		};

		^overrides;
	}

	*prLongAttack { arg dur = 12, voices, overrides = [];
		(overrides.includes(\maxDelay) or: { overrides.includes(\minDelay) }).not.if {
			var delay = { |i| rrand(0.25 * i, 3 * i).round(0.25) } ! voices;

			overrides = overrides.add(\minDelay).add(delay);
			overrides = overrides.add(\maxDelay).add(delay);
		};

		overrides.includes(\env).not.if {
			overrides = overrides.add(\env).add(
				EnvelopeBank.parseEnv(Env([0, 1, 0], [dur - 0.001, 0.001], 3), voices)
			);
		};

		^overrides;
	}

	*prFormatMethodName { arg preset;
		preset = preset.asString;

		^(\pr ++ preset.first.toUpper ++ preset[1..preset.size]).asSymbol;
	}


}