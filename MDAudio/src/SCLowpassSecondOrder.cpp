#include "SCLowpassSecondOrder.hpp"

using md_ugens::LowpassSecondOrder;

LowpassSecondOrder::LowpassSecondOrder() :
    m_filter(
        (md_audio::LowpassSecondOrder::set_sample_rate(sampleRate()), 440.)
    )
{
    if (isAudioRateIn(1) && isAudioRateIn(2))
        set_calc_function<LowpassSecondOrder, &LowpassSecondOrder::next_aa>();
    else if (isAudioRateIn(1) && !isAudioRateIn(2))
        set_calc_function<LowpassSecondOrder, &LowpassSecondOrder::next_ak>();
    else if (!isAudioRateIn(1) && isAudioRateIn(2))
        set_calc_function<LowpassSecondOrder, &LowpassSecondOrder::next_ka>();
    else
        set_calc_function<LowpassSecondOrder, &LowpassSecondOrder::next_kk>();
}

void LowpassSecondOrder::next_aa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto r = in(2);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);
        m_filter.set_r(r[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void LowpassSecondOrder::next_ak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in(1);
    const auto r = in0(2);
    auto outBuf = out(0);

    m_filter.set_r(r);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_frequency(frequency[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void LowpassSecondOrder::next_ka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto r = in(2);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_filter.set_r(r[i]);

        outBuf[i] = m_filter.process(inBuf[i]);
    }
}

void LowpassSecondOrder::next_kk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto r = in0(2);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);
    m_filter.set_r(r);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_filter.process(inBuf[i]);
}