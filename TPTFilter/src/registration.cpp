#include "Lowpass.hpp"
#include "Highpass.hpp"
#include "Allpass.hpp"
#include "Lowshelf.hpp"
#include "Highshelf.hpp"
#include "Tilt.hpp"
#include "SVF.hpp"
#include "Lowpass2.hpp"
#include "Highpass2.hpp"
#include "Bandpass.hpp"
#include "Bandstop.hpp"
#include "Lowshelf2.hpp"
#include "Highshelf2.hpp"
#include "Bandshelf.hpp"
#include "Tilt2.hpp"
#include "Allpass2.hpp"
#include "SC_PlugIn.hpp"

using tpt_filter_ugens::Lowpass;
using tpt_filter_ugens::Highpass;
using tpt_filter_ugens::Allpass;
using tpt_filter_ugens::Lowshelf;
using tpt_filter_ugens::Highshelf;
using tpt_filter_ugens::Tilt;
using tpt_filter_ugens::SVF;
using tpt_filter_ugens::Lowpass2;
using tpt_filter_ugens::Highpass2;
using tpt_filter_ugens::Bandpass;
using tpt_filter_ugens::Bandstop;
using tpt_filter_ugens::Lowshelf2;
using tpt_filter_ugens::Highshelf2;
using tpt_filter_ugens::Bandshelf;
using tpt_filter_ugens::Tilt2;
using tpt_filter_ugens::Allpass2;

static InterfaceTable *ft;

PluginLoad(TPTFilter) {
    ft = inTable;
    registerUnit<Lowpass>(ft, "TPTLowpass");
    registerUnit<Highpass>(ft, "TPTHighpass");
    registerUnit<Allpass>(ft, "TPTAllpass");
    registerUnit<Lowshelf>(ft, "TPTLowshelf");
    registerUnit<Highshelf>(ft, "TPTHighshelf");
    registerUnit<Tilt>(ft, "TPTTilt");
    registerUnit<SVF>(ft, "TPTSVF");
    registerUnit<Lowpass2>(ft, "TPTLowpass2");
    registerUnit<Highpass2>(ft, "TPTHighpass2");
    registerUnit<Bandpass>(ft, "TPTBandpass");
    registerUnit<Bandstop>(ft, "TPTBandstop");
    registerUnit<Lowshelf2>(ft, "TPTLowshelf2");
    registerUnit<Highshelf2>(ft, "TPTHighshelf2");
    registerUnit<Bandshelf>(ft, "TPTBandshelf");
    registerUnit<Tilt2>(ft, "TPTTilt2");
    registerUnit<Allpass2>(ft, "TPTAllpass2");
}
