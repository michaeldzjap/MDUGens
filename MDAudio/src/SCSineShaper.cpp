#include "SCSineShaper.hpp"

using md_ugens::SineShaper;

SineShaper::SineShaper() {
    if (isAudioRateIn(1))
        set_calc_function<SineShaper, &SineShaper::next_a>();
    else
        set_calc_function<SineShaper, &SineShaper::next_k>();
}

void SineShaper::next_a(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto inBuf = in(0);
    const auto limit = in(1);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_shaper.set_limit(limit[i]);

        outBuf[i] = m_shaper.perform(inBuf[i]);
    }
}

void SineShaper::next_k(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto inBuf = in(0);
    const auto limit = in0(1);

    m_shaper.set_limit(limit);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_shaper.perform(inBuf[i]);
}
