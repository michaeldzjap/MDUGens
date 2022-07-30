#include "SCSineOscillator.hpp"

using md_ugens::SineOscillator;

SineOscillator::SineOscillator()
    : m_osc(
        (md_audio::SineOscillator::set_sample_rate(sampleRate()), 440.f)
    )
{
    if (isAudioRateIn(0) && isAudioRateIn(1))
        set_calc_function<SineOscillator, &SineOscillator::next_aa>();
    else if (isAudioRateIn(0) && !isAudioRateIn(1))
        set_calc_function<SineOscillator, &SineOscillator::next_ak>();
    else if (!isAudioRateIn(0) && isAudioRateIn(1))
        set_calc_function<SineOscillator, &SineOscillator::next_ka>();
    else
        set_calc_function<SineOscillator, &SineOscillator::next_kk>();
}

void SineOscillator::next_aa(int inNumSamples) noexcept {
    auto *outBuf = out(0);
    const auto *frequency = in(0);
    const auto *phase = in(1);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_osc.set_frequency(frequency[i]);
        m_osc.set_phase(phase[i]);

        outBuf[i] = m_osc.perform();
    }
}

void SineOscillator::next_ak(int inNumSamples) noexcept {
    auto *outBuf = out(0);
    const auto *frequency = in(0);
    const auto phase = in0(1);

    m_osc.set_phase(phase);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_osc.set_frequency(frequency[i]);

        outBuf[i] = m_osc.perform();
    }
}

void SineOscillator::next_ka(int inNumSamples) noexcept {
    auto *outBuf = out(0);
    const auto frequency = in0(0);
    const auto *phase = in(1);

    m_osc.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_osc.set_phase(phase[i]);

        outBuf[i] = m_osc.perform();
    }
}

void SineOscillator::next_kk(int inNumSamples) noexcept {
    auto *outBuf = out(0);
    const auto frequency = in0(0);
    const auto phase = in0(1);

    m_osc.set_frequency(frequency);
    m_osc.set_phase(phase);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_osc.perform();
}
