#include "SCDelay.hpp"
#include "InterpolationType.hpp"

using md_audio::InterpolationType;
using md_ugens::Delay;

Delay::Delay() :
    m_pool(mWorld),
    m_delay(
        (md_audio::Delay::set_sample_rate(sampleRate()), m_pool),
        in0(1),
        in0(2),
        static_cast<InterpolationType>(in0(3))
    )
{
    if (isAudioRateIn(2))
        set_calc_function<Delay, &Delay::next_a>();
    else {
        m_delay_time = in0(2);
        set_calc_function<Delay, &Delay::next_k>();
    }
}

void Delay::next_a(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay.set_delay(delay[i]);

        outBuf[i] = m_delay.perform(inBuf[i]);
    }
}

void Delay::next_k(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in0(2);
    auto outBuf = out(0);

    const auto delay_slope = calcSlope(in0(2), m_delay_time);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;

        m_delay.set_delay(m_delay_time);

        outBuf[i] = m_delay.perform(inBuf[i]);
    }
}

void Delay::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
