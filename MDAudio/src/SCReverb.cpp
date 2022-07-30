#include "SCReverb.hpp"

using md_ugens::Reverb;

Reverb::Reverb() :
    m_pool(mWorld),
    m_reverb(
        (md_audio::Reverb::set_sample_rate(sampleRate()), m_pool)
    )
{
    set_calc_function<Reverb, &Reverb::next>();
}

void Reverb::next(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto size = in0(1);
    const auto decay = in0(2);
    const auto absorb = in0(3);
    const auto pre_delay = in0(4);
    const auto reverse = static_cast<bool>(in0(5));
    const auto rate = in0(6);
    const auto depth = in0(7);
    const auto shimmer = in0(8);
    const auto tilt = in0(9);
    const auto mix = in0(10);
    auto outBufL = out(0);
    auto outBufR = out(1);

    m_reverb.set_size(size);
    m_reverb.set_decay(decay);
    m_reverb.set_absorb(absorb);
    m_reverb.set_pre_delay(pre_delay);
    m_reverb.set_reverse(reverse);
    m_reverb.set_modulation_rate(rate);
    m_reverb.set_modulation_depth(depth);
    m_reverb.set_shimmer(shimmer);
    m_reverb.set_tilt(tilt);
    m_reverb.set_mix(mix);

    for (auto i = 0; i < inNumSamples; ++i) {
        auto z = m_reverb.perform(inBuf[i]);

        outBufL[i] = z[0];
        outBufR[i] = z[1];
    }
}

void Reverb::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
