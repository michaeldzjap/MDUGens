#include "SCPhasor.hpp"

using md_ugens::Phasor;

Phasor::Phasor() :
    m_phasor(
        (md_audio::Phasor::set_sample_rate(sampleRate()), in0(0)),
        in0(1)
    )
{
    if (isAudioRateIn(0))
        set_calc_function<Phasor, &Phasor::next_a>();
    else
        set_calc_function<Phasor, &Phasor::next_k>();
}

void Phasor::next_a(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto frequency = in(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_phasor.set_frequency(frequency[i]);

        outBuf[i] = m_phasor.perform();
    }
}

void Phasor::next_k(int inNumSamples) noexcept {
    auto outBuf = out(0);
    const auto frequency = in0(0);

    m_phasor.set_frequency(frequency);

    for (auto i = 0; i < inNumSamples; ++i)
        outBuf[i] = m_phasor.perform();
}
