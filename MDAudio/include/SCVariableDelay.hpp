#ifndef MD_UGENS_VARIABLE_DELAY_HPP
#define MD_UGENS_VARIABLE_DELAY_HPP

#include "SCAllocator.hpp"
#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "VariableDelay.hpp"

namespace md_ugens {

    class VariableDelay : public SCUnit {
    public:
        explicit VariableDelay();

    private:
        memory::SCPool m_pool;
        memory::SCAllocator<double, memory::SCPool> m_allocator;
        md_audio::VariableDelay<memory::SCAllocator<double, memory::SCPool>> m_delay;
        float m_delay_time;
        float m_size;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_VARIABLE_DELAY_HPP */
