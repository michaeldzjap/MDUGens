#include "SCLowpassFirstOrder.hpp"

using md_ugens::LowpassFirstOrder;

LowpassFirstOrder::LowpassFirstOrder() :
    m_filter(
        (md_audio::LowpassFirstOrder::set_sample_rate(sampleRate()), 440.)
    )
{
    if (isAudioRateIn(1))
        set_calc_function<LowpassFirstOrder, &LowpassFirstOrder::next_a>();
    else
        set_calc_function<LowpassFirstOrder, &LowpassFirstOrder::next_k>();
}

void LowpassFirstOrder::next_a(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void LowpassFirstOrder::next_k(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_filter.process(inBuf[i]);
}
