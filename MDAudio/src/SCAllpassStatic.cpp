#include "SCAllpassStatic.hpp"

using md_ugens::AllpassStatic;

AllpassStatic::AllpassStatic() :
    m_pool(mWorld),
    m_allocator(&m_pool),
    m_allpass(
        (
            md_audio::AllpassStatic<memory::SCAllocator<double, memory::SCPool>>::set_sample_rate(sampleRate()),
            m_allocator
        ),
        in0(1),
        in0(2),
        in0(3)
    )
{
    if (!m_allpass.initialise()) {
        printf("Could not allocate real-time memory for MDAllpassStatic\n");

        set_calc_function<AllpassStatic, &AllpassStatic::clear>();

        return;
    }

    if (isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<AllpassStatic, &AllpassStatic::next_aa>();
    else if (isAudioRateIn(2) && !isAudioRateIn(3)) {
        m_gain = in0(3);

        set_calc_function<AllpassStatic, &AllpassStatic::next_ak>();
    } else if (!isAudioRateIn(2) && isAudioRateIn(3)) {
        m_delay_time = in0(2);

        set_calc_function<AllpassStatic, &AllpassStatic::next_ka>();
    } else {
        m_delay_time = in0(2);
        m_gain = in0(3);

        set_calc_function<AllpassStatic, &AllpassStatic::next_kk>();
    }
}

void AllpassStatic::next_aa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    const auto gain = in(3);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_allpass.set_delay_time(delay[i]);
        m_allpass.set_gain(gain[i]);

        outBuf[i] = m_allpass.process(inBuf[i]);
    }
}

void AllpassStatic::next_ak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    auto outBuf = out(0);

    const auto gain_slope = calcSlope(in0(3), m_gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_gain += gain_slope;

        m_allpass.set_delay_time(delay[i]);
        m_allpass.set_gain(m_gain);

        outBuf[i] = m_allpass.process(inBuf[i]);
    }
}

void AllpassStatic::next_ka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto gain = in(3);
    auto outBuf = out(0);

    const auto delay_slope = calcSlope(in0(2), m_delay_time);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;

        m_allpass.set_delay_time(m_delay_time);
        m_allpass.set_gain(gain[i]);

        outBuf[i] = m_allpass.process(inBuf[i]);
    }
}

void AllpassStatic::next_kk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    auto outBuf = out(0);

    const auto delay_slope = calcSlope(in0(2), m_delay_time);
    const auto gain_slope = calcSlope(in0(3), m_gain);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;
        m_gain += gain_slope;

        m_allpass.set_delay_time(m_delay_time);
        m_allpass.set_gain(m_gain);

        outBuf[i] = m_allpass.process(inBuf[i]);
    }
}

void AllpassStatic::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
