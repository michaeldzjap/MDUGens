#ifndef MD_UGENS_DELAY_LINEAR_HPP
#define MD_UGENS_DELAY_LINEAR_HPP

#include "SCAllocator.hpp"
#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "DelayLinear.hpp"

namespace md_ugens {

    class DelayLinear : public SCUnit {
    public:
        explicit DelayLinear();

    private:
        memory::SCPool m_pool;
        memory::SCAllocator<double, memory::SCPool> m_allocator;
        md_audio::DelayLinear<memory::SCAllocator<double, memory::SCPool>> m_delay;
        float m_delay_time;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_DELAY_LINEAR_HPP */
