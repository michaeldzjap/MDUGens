#include "SCHannOscillator.hpp"

using md_ugens::HannOscillator;

HannOscillator::HannOscillator() :
    m_osc(
        (md_audio::HannOscillator::set_sample_rate(sampleRate()), 440.f)
    )
{
    if (isAudioRateIn(0) && isAudioRateIn(1))
        set_calc_function<HannOscillator, &HannOscillator::next_aa>();
    else if (isAudioRateIn(0) && !isAudioRateIn(1))
        set_calc_function<HannOscillator, &HannOscillator::next_ak>();
    else if (!isAudioRateIn(0) && isAudioRateIn(1))
        set_calc_function<HannOscillator, &HannOscillator::next_ka>();
    else
        set_calc_function<HannOscillator, &HannOscillator::next_kk>();
}

void HannOscillator::next_aa(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto frequency = in(0);
    const auto phase = in(1);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_osc.set_frequency(frequency[i]);
        m_osc.set_frequency(phase[i]);

        outBuf[i] = m_osc.perform();
    }
}

void HannOscillator::next_ak(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto frequency = in(0);
    const auto phase = in0(1);

    m_osc.set_phase(phase);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_osc.set_frequency(frequency[i]);

        outBuf[i] = m_osc.perform();
    }
}

void HannOscillator::next_ka(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto frequency = in0(0);
    const auto phase = in(1);

    m_osc.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_osc.set_phase(phase[i]);

        outBuf[i] = m_osc.perform();
    }
}

void HannOscillator::next_kk(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto frequency = in0(0);
    const auto phase = in0(1);

    m_osc.set_frequency(frequency);
    m_osc.set_phase(phase);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_osc.perform();
}
