#include "SCAllpassCubic.hpp"

using md_audio::MdFloat;
using md_ugens::AllpassCubic;

AllpassCubic::AllpassCubic() :
    m_pool(mWorld),
    m_allpass(
        (md_audio::AllpassCubic::set_sample_rate(sampleRate()), m_pool),
        in0(1),
        in0(2),
        in0(3)
    )
{
    if (isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<AllpassCubic, &AllpassCubic::next_aa>();
    else if (isAudioRateIn(2) && !isAudioRateIn(3)) {
        m_gain = in0(3);
        set_calc_function<AllpassCubic, &AllpassCubic::next_ak>();
    } else if (!isAudioRateIn(2) && isAudioRateIn(3)) {
        m_delay_time = in0(2);
        set_calc_function<AllpassCubic, &AllpassCubic::next_ka>();
    } else {
        m_delay_time = in0(2);
        m_gain = in0(3);
        set_calc_function<AllpassCubic, &AllpassCubic::next_kk>();
    }
}

void AllpassCubic::next_aa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    const auto gain = in(3);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_allpass.set_delay(delay[i]);
        m_allpass.set_gain(gain[i]);

        outBuf[i] = m_allpass.perform(inBuf[i]);
    }
}

void AllpassCubic::next_ak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    auto outBuf = out(0);

    const auto gain_slope = calcSlope(in0(3), m_gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_gain += gain_slope;

        m_allpass.set_delay(delay[i]);
        m_allpass.set_gain(m_gain);

        outBuf[i] = m_allpass.perform(inBuf[i]);
    }
}

void AllpassCubic::next_ka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto gain = in(3);
    auto outBuf = out(0);

    const auto delay_slope = calcSlope(in0(2), m_delay_time);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;

        m_allpass.set_delay(m_delay_time);
        m_allpass.set_gain(gain[i]);

        outBuf[i] = m_allpass.perform(inBuf[i]);
    }
}

void AllpassCubic::next_kk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    auto outBuf = out(0);

    const auto delay_slope = calcSlope(in0(2), m_delay_time);
    const auto gain_slope = calcSlope(in0(3), m_gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;
        m_gain += gain_slope;

        m_allpass.set_delay(m_delay_time);
        m_allpass.set_gain(m_gain);

        outBuf[i] = m_allpass.perform(inBuf[i]);
    }
}

void AllpassCubic::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
