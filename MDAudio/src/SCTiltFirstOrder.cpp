#include "SCTiltFirstOrder.hpp"

using md_ugens::TiltFirstOrder;

TiltFirstOrder::TiltFirstOrder() :
    m_filter(
        (md_audio::TiltFirstOrder::set_sample_rate(sampleRate()), 440., 0.)
    )
{
    if (isAudioRateIn(1) && isAudioRateIn(2))
        set_calc_function<TiltFirstOrder, &TiltFirstOrder::next_aa>();
    else if (isAudioRateIn(1) && !isAudioRateIn(2))
        set_calc_function<TiltFirstOrder, &TiltFirstOrder::next_ak>();
    else if (!isAudioRateIn(1) && isAudioRateIn(2))
        set_calc_function<TiltFirstOrder, &TiltFirstOrder::next_ka>();
    else
        set_calc_function<TiltFirstOrder, &TiltFirstOrder::next_kk>();
}

void TiltFirstOrder::next_aa(int inNumSamples) noexcept {
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

void TiltFirstOrder::next_ak(int inNumSamples) noexcept {
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

void TiltFirstOrder::next_ka(int inNumSamples) noexcept {
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

void TiltFirstOrder::next_kk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto frequency = in0(1);
    const auto gain = in0(2);
    auto outBuf = out(0);

    m_filter.set_frequency(frequency);
    m_filter.set_gain(gain);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_filter.process(inBuf[i]);
}
