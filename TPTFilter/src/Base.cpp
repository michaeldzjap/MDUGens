#include "Base.hpp"
#include "SC_PlugIn.hpp"

using tpt_filter_ugens::Base;

Base::Base() : mSr2(0.5 * sampleRate()), mA(pi * sampleDur()) {}
