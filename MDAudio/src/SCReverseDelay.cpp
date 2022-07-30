#include "SCReverseDelay.hpp"

using md_ugens::ReverseDelay;

ReverseDelay::ReverseDelay() :
    m_pool(mWorld),
    m_reverser(
        (md_audio::ReverseDelay::set_sample_rate(sampleRate()), m_pool),
        in0(1),
        in0(2),
        in0(3)
    )
{
    if (isAudioRateIn(2))
        set_calc_function<ReverseDelay, &ReverseDelay::next_a>();
    else {
        m_size = in0(2);
        set_calc_function<ReverseDelay, &ReverseDelay::next_k>();
    }
}

void ReverseDelay::next_a(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto size = in(2);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_reverser.set_size(sampleRate() * size[i]);

        outBuf[i] = m_reverser.perform(inBuf[i]);
    }
}

void ReverseDelay::next_k(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    auto outBuf = out(0);

    const auto size_slope = calcSlope(in0(2), m_size);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_size += size_slope;

        m_reverser.set_size(m_size);

        outBuf[i] = m_reverser.perform(inBuf[i]);
    }
}

void ReverseDelay::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
