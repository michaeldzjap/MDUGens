#include "SCAllpassCubic.hpp"
#include "SCAllpassFirstOrder.hpp"
#include "SCAllpassLinear.hpp"
#include "SCAllpassSecondOrder.hpp"
#include "SCAllpassStatic.hpp"
#include "SCBandpass.hpp"
#include "SCBandshelf.hpp"
#include "SCBandstop.hpp"
#include "SCDelayCubic.hpp"
#include "SCDelayLinear.hpp"
#include "SCDelayStatic.hpp"
// #include "SCHannOscillator.hpp"
#include "SCHighpassFirstOrder.hpp"
#include "SCHighpassSecondOrder.hpp"
#include "SCHighshelfFirstOrder.hpp"
#include "SCHighshelfSecondOrder.hpp"
#include "SCLowpassFirstOrder.hpp"
#include "SCLowpassSecondOrder.hpp"
#include "SCLowshelfFirstOrder.hpp"
#include "SCLowshelfSecondOrder.hpp"
// #include "SCPhasor.hpp"
// #include "SCPitchShifter.hpp"
// #include "SCReverb.hpp"
// #include "SCReverseDelay.hpp"
// #include "SCReversibleDelay.hpp"
// #include "SCSineOscillator.hpp"
// #include "SCSineShaper.hpp"
// #include "SCTapDelay.hpp"
// #include "SCTapDelayCubic.hpp"
// #include "SCTapDelayLinear.hpp"
// #include "SCTapDelayStatic.hpp"
#include "SCTiltFirstOrder.hpp"
#include "SCTiltSecondOrder.hpp"
// #include "SCVariableDelay.hpp"
#include "SCWhiteNoise.hpp"
#include "registration.hpp"

using md_ugens::AllpassCubic;
using md_ugens::AllpassFirstOrder;
using md_ugens::AllpassLinear;
using md_ugens::AllpassSecondOrder;
using md_ugens::AllpassStatic;
using md_ugens::Bandpass;
using md_ugens::Bandshelf;
using md_ugens::Bandstop;
using md_ugens::DelayCubic;
using md_ugens::DelayLinear;
using md_ugens::DelayStatic;
// using md_ugens::HannOscillator;
using md_ugens::HighpassFirstOrder;
using md_ugens::HighpassSecondOrder;
using md_ugens::HighshelfFirstOrder;
using md_ugens::HighshelfSecondOrder;
using md_ugens::LowpassFirstOrder;
using md_ugens::LowpassSecondOrder;
using md_ugens::LowshelfFirstOrder;
using md_ugens::LowshelfSecondOrder;
// using md_ugens::Phasor;
// using md_ugens::PitchShifter;
// using md_ugens::Reverb;
// using md_ugens::ReverseDelay;
// using md_ugens::ReversibleDelay;
// using md_ugens::SineOscillator;
// using md_ugens::SineShaper;
// using md_ugens::TapDelay;
// using md_ugens::TapDelayCubic;
// using md_ugens::TapDelayLinear;
// using md_ugens::TapDelayStatic;
using md_ugens::TiltFirstOrder;
using md_ugens::TiltSecondOrder;
// using md_ugens::VariableDelay;
using md_ugens::WhiteNoise;

InterfaceTable *ft;

PluginLoad(MDAudio) {
    ft = inTable;
    registerUnit<AllpassCubic>(ft, "MDAllpassCubic");
    registerUnit<AllpassLinear>(ft, "MDAllpassLinear");
    registerUnit<AllpassFirstOrder>(ft, "MDAllpassFirstOrder");
    registerUnit<AllpassSecondOrder>(ft, "MDAllpassSecondOrder");
    registerUnit<AllpassStatic>(ft, "MDAllpassStatic");
    registerUnit<Bandpass>(ft, "MDBandpass");
    registerUnit<Bandshelf>(ft, "MDBandshelf");
    registerUnit<Bandstop>(ft, "MDBandstop");
    registerUnit<DelayStatic>(ft, "MDDelayStatic");
    registerUnit<DelayCubic>(ft, "MDDelayCubic");
    registerUnit<DelayLinear>(ft, "MDDelayLinear");
    // registerUnit<HannOscillator>(ft, "MD_HannOscillator");
    registerUnit<HighpassFirstOrder>(ft, "MDHighpassFirstOrder");
    registerUnit<HighpassSecondOrder>(ft, "MDHighpassSecondOrder");
    registerUnit<HighshelfFirstOrder>(ft, "MDHighshelfFirstOrder");
    registerUnit<HighshelfSecondOrder>(ft, "MDHighshelfSecondOrder");
    registerUnit<LowpassFirstOrder>(ft, "MDLowpassFirstOrder");
    registerUnit<LowpassSecondOrder>(ft, "MDLowpassSecondOrder");
    registerUnit<LowshelfFirstOrder>(ft, "MDLowshelfFirstOrder");
    registerUnit<LowshelfSecondOrder>(ft, "MDLowshelfSecondOrder");
    // registerUnit<Phasor>(ft, "MD_Phasor");
    // registerUnit<PitchShifter>(ft, "MD_PitchShifter");
    // registerUnit<Reverb>(ft, "MD_Reverb");
    // registerUnit<ReverseDelay>(ft, "MD_ReverseDelay");
    // registerUnit<ReversibleDelay>(ft, "MD_ReversibleDelay");
    // registerUnit<SineOscillator>(ft, "MD_SineOscillator");
    // registerUnit<SineShaper>(ft, "MD_SineShaper");
    // registerUnit<TapDelay>(ft, "MD_TapDelay");
    // registerUnit<TapDelayCubic>(ft, "MD_TapDelayCubic");
    // registerUnit<TapDelayLinear>(ft, "MD_TapDelayLinear");
    // registerUnit<TapDelayStatic>(ft, "MD_TapDelayStatic");
    registerUnit<TiltFirstOrder>(ft, "MDTiltFirstOrder");
    registerUnit<TiltSecondOrder>(ft, "MDTiltSecondOrder");
    // registerUnit<VariableDelay>(ft, "MD_VariableDelay");
    registerUnit<WhiteNoise>(ft, "MDWhiteNoise");
}
