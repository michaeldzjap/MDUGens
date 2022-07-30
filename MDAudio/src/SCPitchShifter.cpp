#include "SCPitchShifter.hpp"

using md_ugens::PitchShifter;

PitchShifter::PitchShifter() :
    m_pool(mWorld),
    m_shifter(
        (md_audio::PitchShifter::set_sample_rate(sampleRate()), m_pool),
        in0(1),
        in0(2),
        in0(3),
        in0(4)
    )
{
    if (isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<PitchShifter, &PitchShifter::next_aa>();
    else if (isAudioRateIn(2) && !isAudioRateIn(3)) {
        m_transposition = in0(3);
        set_calc_function<PitchShifter, &PitchShifter::next_ak>();
    } else if (!isAudioRateIn(2) && isAudioRateIn(3)) {
        m_size = in0(2);
        set_calc_function<PitchShifter, &PitchShifter::next_ka>();
    } else {
        m_size = in0(2);
        m_transposition = in0(3);
        set_calc_function<PitchShifter, &PitchShifter::next_kk>();
    }
}

void PitchShifter::next_aa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto size = in(2);
    const auto transposition = in(3);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_shifter.set_size(size[i]);
        m_shifter.set_transposition(transposition[i]);

        outBuf[i] = m_shifter.perform(inBuf[i]);
    }
}

void PitchShifter::next_ak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto size = in(2);
    auto outBuf = out(0);

    const auto transposition_slope = calcSlope(in0(3), m_transposition);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_transposition += transposition_slope;

        m_shifter.set_size(sampleRate() * size[i]);
        m_shifter.set_transposition(m_transposition);

        outBuf[i] = m_shifter.perform(inBuf[i]);
    }
}

void PitchShifter::next_ka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto transposition = in(3);
    auto outBuf = out(0);

    const auto size_slope = calcSlope(in0(2), m_size);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_size += size_slope;

        m_shifter.set_size(m_size);
        m_shifter.set_transposition(transposition[i]);

        outBuf[i] = m_shifter.perform(inBuf[i]);
    }
}

void PitchShifter::next_kk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    auto outBuf = out(0);

    const auto size_slope = calcSlope(in0(2), m_size);
    const auto transposition_slope = calcSlope(in0(3), m_transposition);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_size += size_slope;
        m_transposition += transposition_slope;

        m_shifter.set_size(m_size);
        m_shifter.set_transposition(m_transposition);

        outBuf[i] = m_shifter.perform(inBuf[i]);
    }
}

void PitchShifter::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
