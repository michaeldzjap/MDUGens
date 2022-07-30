#include "SCReversibleDelay.hpp"
#include <iostream>
#include <memory>

using md_audio::MdFloat;
using md_ugens::memory::SCAllocator;
using md_ugens::memory::SCPool;
using md_ugens::ReversibleDelay;

ReversibleDelay::ReversibleDelay() :
    m_pool(SCPool(mWorld)),
    m_allocator(&m_pool),
    m_reversible_delay(
        m_allocator,
        static_cast<std::uint32_t>(sampleRate() * in0(1)) + 3,
        sampleRate() * in0(2)
    )
{
    try {
        m_reversible_delay.initialise();
    } catch (const std::bad_alloc&) {
        std::cout << "Could not allocate real-time memory for ReversibleDelay" << std::endl;
        set_calc_function<ReversibleDelay, &ReversibleDelay::clear>();

        return;
    }

    if (isAudioRateIn(2)) {
        set_calc_function<ReversibleDelay, &ReversibleDelay::next_a>();
    } else {
        set_calc_function<ReversibleDelay, &ReversibleDelay::next_k>();
    }
}

void ReversibleDelay::next_a(int inNumSamples) noexcept {
    const float *inBuf = in(0);
    const float *delay = in(2);
    const bool reversed = static_cast<bool>(in0(3));
    float *outBuf = out(0);

    auto reversible_delay = m_reversible_delay;
    auto is_reversed = reversible_delay.is_reversed();

    if (is_reversed != reversed)
        reversible_delay.toggle_reverse();

    for (auto i = 0; i < inNumSamples; i++) {
        if (is_reversed)
            reversible_delay.set_backward_delay(sampleRate() * delay[i]);
        else
            reversible_delay.set_forward_delay(sampleRate() * delay[i]);

        outBuf[i] = reversible_delay.perform(inBuf[i]);
    }
}

void ReversibleDelay::next_k(int inNumSamples) noexcept {
    const float *inBuf = in(0);
    const float delay = in0(2);
    const bool reversed = static_cast<bool>(in0(3));
    float *outBuf = out(0);

    auto reversible_delay = m_reversible_delay;
    auto is_reversed = reversible_delay.is_reversed();

    if (is_reversed != reversed)
        reversible_delay.toggle_reverse();

    if (is_reversed)
        reversible_delay.set_backward_delay(sampleRate() * delay);
    else
        reversible_delay.set_forward_delay(sampleRate() * delay);

    for (auto i = 0; i < inNumSamples; i++)
        outBuf[i] = reversible_delay.perform(inBuf[i]);
}

void ReversibleDelay::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}
