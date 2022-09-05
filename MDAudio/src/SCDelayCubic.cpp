#include "SCDelayCubic.hpp"

using md_ugens::DelayCubic;

DelayCubic::DelayCubic() :
    m_pool(mWorld),
    m_allocator(&m_pool),
    m_delay(
        (
            md_audio::DelayCubic<memory::SCAllocator<double, memory::SCPool>>::set_sample_rate(sampleRate()),
            m_allocator
        ),
        in0(1),
        in0(2)
    )
{
    if (!m_delay.initialise()) {
        printf("Could not allocate real-time memory for MDDelayCubic\n");

        set_calc_function<DelayCubic, &DelayCubic::clear>();

        return;
    }

    if (isAudioRateIn(2))
        set_calc_function<DelayCubic, &DelayCubic::next_a>();
    else {
        m_delay_time = in0(2);
        set_calc_function<DelayCubic, &DelayCubic::next_k>();
    }
}

void DelayCubic::next_a(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in(2);
    auto outBuf = out(0);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay.set_delay_time(delay[i]);

        outBuf[i] = m_delay.process(inBuf[i]);
    }
}

void DelayCubic::next_k(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto delay = in0(2);
    auto outBuf = out(0);

    const auto delay_slope = calcSlope(in0(2), m_delay_time);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_delay_time += delay_slope;

        m_delay.set_delay_time(m_delay_time);

        outBuf[i] = m_delay.process(inBuf[i]);
    }
}

void DelayCubic::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}