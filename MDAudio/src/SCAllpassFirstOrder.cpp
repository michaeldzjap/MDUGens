#include "SCAllpassFirstOrder.hpp"

using md_ugens::AllpassFirstOrder;

AllpassFirstOrder::AllpassFirstOrder() :
    m_filter(
        (md_audio::AllpassFirstOrder::set_sample_rate(sampleRate()), 440.)
    )
{
    if (isAudioRateIn(1))
        set_calc_function<AllpassFirstOrder, &AllpassFirstOrder::next_a>();
    else
        set_calc_function<AllpassFirstOrder, &AllpassFirstOrder::next_k>();
}

void AllpassFirstOrder::next_a(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void AllpassFirstOrder::next_k(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_filter.process(inBuf[i]);
}
