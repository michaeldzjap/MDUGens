#include "SCLowshelfFirstOrder.hpp"

using md_ugens::LowshelfFirstOrder;

LowshelfFirstOrder::LowshelfFirstOrder() :
    m_filter(
        (md_audio::LowshelfFirstOrder::set_sample_rate(sampleRate()), 440., 0.)
    )
{
    if (isAudioRateIn(1) && isAudioRateIn(2))
        set_calc_function<LowshelfFirstOrder, &LowshelfFirstOrder::next_aa>();
    else if (isAudioRateIn(1) && !isAudioRateIn(2))
        set_calc_function<LowshelfFirstOrder, &LowshelfFirstOrder::next_ak>();
    else if (!isAudioRateIn(1) && isAudioRateIn(2))
        set_calc_function<LowshelfFirstOrder, &LowshelfFirstOrder::next_ka>();
    else
        set_calc_function<LowshelfFirstOrder, &LowshelfFirstOrder::next_kk>();
}

void LowshelfFirstOrder::next_aa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto gain = in(2);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);
        m_filter.set_gain(gain[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void LowshelfFirstOrder::next_ak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto gain = in0(2);
    auto outBuf = out(0);

    m_filter.set_gain(gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void LowshelfFirstOrder::next_ka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto gain = in(2);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_gain(gain[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void LowshelfFirstOrder::next_kk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto gain = in0(2);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);
    m_filter.set_gain(gain);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_filter.process(inBuf[i]);
}
