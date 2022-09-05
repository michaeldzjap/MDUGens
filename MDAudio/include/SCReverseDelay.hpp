#ifndef MD_UGENS_REVERSE_DELAY_HPP
#define MD_UGENS_REVERSE_DELAY_HPP

#include "SCAllocator.hpp"
#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "ReverseDelay.hpp"

namespace md_ugens {

    class ReverseDelay : public SCUnit {
    public:
        explicit ReverseDelay();

    private:
        memory::SCPool m_pool;
        memory::SCAllocator<double, memory::SCPool> m_allocator;
        md_audio::ReverseDelay<memory::SCAllocator<double, memory::SCPool>> m_reverser;
        float m_size;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_REVERSE_DELAY_HPP */
