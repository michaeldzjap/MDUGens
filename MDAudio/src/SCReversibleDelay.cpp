#include "SCReversibleDelay.hpp"

using md_ugens::ReversibleDelay;

ReversibleDelay::ReversibleDelay() :
    m_pool(mWorld),
    m_reverser(
        (md_audio::ReversibleDelay::set_sample_rate(sampleRate()), m_pool),
        in0(1),
        in0(2),
        static_cast<bool>(in0(3)),
        in0(4)
    )
{
    if (isAudioRateIn(2))
        set_calc_function<ReversibleDelay, &ReversibleDelay::next_a>();
    else {
        m_size = in0(2);
        set_calc_function<ReversibleDelay, &ReversibleDelay::next_k>();
    }
}

void ReversibleDelay::next_a(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto size = in(2);
    const auto reverse = static_cast<bool>(in0(3));
    auto outBuf = out(0);

    if (reverse != m_reverser.is_reversed())
        m_reverser.toggle_reverse();

    for (auto i = 0; i < inNumSamples; ++i) {
        if (m_reverser.is_reversed())
            m_reverser.set_backward_delay(size[i]);
        else
            m_reverser.set_forward_delay(size[i]);

        outBuf[i] = m_reverser.perform(inBuf[i]);
    }
}

void ReversibleDelay::next_k(int inNumSamples) noexcept {
    const auto inBuf = in(0);
    const auto reverse = static_cast<bool>(in0(3));
    auto outBuf = out(0);

    if (reverse != m_reverser.is_reversed())
        m_reverser.toggle_reverse();

    const auto size_slope = calcSlope(in0(2), m_size);

    for (auto i = 0; i < inNumSamples; ++i) {
        m_size += size_slope;

        m_reverser.is_reversed()
            ? m_reverser.set_backward_delay(m_size)
            : m_reverser.set_forward_delay(m_size);

        outBuf[i] = m_reverser.perform(inBuf[i]);
    }
}

void ReversibleDelay::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
