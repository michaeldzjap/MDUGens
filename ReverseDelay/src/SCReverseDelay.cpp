#include "SCReverseDelay.hpp"
#include <cstring>
#include <iostream>
#include <memory>

using md_audio::MdFloat;
using md_ugens::memory::SCAllocator;
using md_ugens::memory::SCPool;
using md_ugens::ReverseDelay;

ReverseDelay::ReverseDelay() :
    m_pool(SCPool(mWorld)),
    m_allocator(&m_pool)/*,
    m_reverse_delay(
        m_allocator,
        static_cast<std::uint32_t>(sampleRate() * in0(1)) + 3,
        sampleRate() * in0(2)
    )*/
{
    // try {
    //     m_reverse_delay.initialise();
    // } catch (const std::bad_alloc&) {
    //     std::cout << "Could not allocate real-time memory for ReverseDelay" << std::endl;
    //     set_calc_function<ReverseDelay, &ReverseDelay::clear>();
    //
    //     return;
    // }

    auto size = static_cast<std::uint32_t>(sampleRate() * in0(1) + 3);

    try {
        m_memory = m_allocator.allocate(size);
    } catch (const std::bad_alloc&) {
        std::cout << "Could not allocate real-time memory for ReverseDelay" << std::endl;
        set_calc_function<ReverseDelay, &ReverseDelay::clear>();

        return;
    }

    std::memset(m_memory, 0, size * sizeof(MdFloat));

    if (isAudioRateIn(2)) {
        set_calc_function<ReverseDelay, &ReverseDelay::next_a>();
    } else {
        set_calc_function<ReverseDelay, &ReverseDelay::next_k>();
    }
}

void ReverseDelay::next_a(int inNumSamples) noexcept {
    const float *inBuf = in(0);
    const float *delay = in(2);
    float *outBuf = out(0);

    // auto reverse_delay = m_reverse_delay;

    for (auto i = 0; i < inNumSamples; i++) {
        // reverse_delay.set_size(sampleRate() * delay[i]);
        //
        // outBuf[i] = reverse_delay.perform(inBuf[i]);

        outBuf[i] = 0.f;
    }
}

void ReverseDelay::next_k(int inNumSamples) noexcept {
    const float *inBuf = in(0);
    const float delay = in0(2);
    float *outBuf = out(0);

    // auto reverse_delay = m_reverse_delay;
    //
    // reverse_delay.set_size(sampleRate() * delay);

    for (auto i = 0; i < inNumSamples; i++)
        // outBuf[i] = reverse_delay.perform(inBuf[i]);
        outBuf[i] = 0.f;
}

void ReverseDelay::clear(int inNumSamples) {
    ClearUnitOutputs(this, inNumSamples);
}

ReverseDelay::~ReverseDelay() {
    m_allocator.deallocate(m_memory);
}
