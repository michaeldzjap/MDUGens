#include "SCVariableDelay.hpp"

using md_ugens::VariableDelay;

VariableDelay::VariableDelay() :
    m_pool(mWorld),
    m_allocator(&m_pool),
    m_delay(
        (
            md_audio::VariableDelay<memory::SCAllocator<double, memory::SCPool>>::set_sample_rate(sampleRate()),
            m_allocator
        ),
        in0(1),
        in0(2),
        in0(3)
    )
{
    if (!m_delay.initialise()) {
        printf("Could not allocate real-time memory for MDVariableDelay\n");

        set_calc_function<VariableDelay, &VariableDelay::clear>();

        return;
    }

    if (isAudioRateIn(2) && isAudioRateIn(3))
        set_calc_function<VariableDelay, &VariableDelay::next_aa>();
    else if (isAudioRateIn(2) && !isAudioRateIn(3)) {
        m_size = in0(3);

        set_calc_function<VariableDelay, &VariableDelay::next_ak>();
    } else if (!isAudioRateIn(2) && isAudioRateIn(3)) {
        m_delay_time = in0(2);

        set_calc_function<VariableDelay, &VariableDelay::next_ka>();
    } else {
        m_delay_time = in0(2);
        m_size = in0(3);

        set_calc_function<VariableDelay, &VariableDelay::next_kk>();
    }
}

void VariableDelay::next_aa(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    const auto size = in(3);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay.set_delay_time(delay[i]);
        m_delay.set_size(size[i]);

        outBuf[i] = m_delay.process(inBuf[i]);
    }
}

void VariableDelay::next_ak(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    auto outBuf = out(0);

    auto size_slope = calcSlope(in0(3), m_size);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_size += size_slope;

        m_delay.set_delay_time(delay[i]);
        m_delay.set_size(m_size);

        outBuf[i] = m_delay.process(inBuf[i]);
    }
}

void VariableDelay::next_ka(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto size = in(3);
    auto outBuf = out(0);

    auto delay_slope = calcSlope(in0(2), m_delay_time);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;

        m_delay.set_delay_time(m_delay_time);
        m_delay.set_size(size[i]);

        outBuf[i] = m_delay.process(inBuf[i]);
    }
}

void VariableDelay::next_kk(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    auto outBuf = out(0);

    auto delay_slope = calcSlope(in0(2), m_delay_time);
    auto size_slope = calcSlope(in0(3), m_size);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;
        m_size += size_slope;

        m_delay.set_delay_time(m_delay_time);
        m_delay.set_size(m_size);

        outBuf[i] = m_delay.process(inBuf[i]);
    }
}

void VariableDelay::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
