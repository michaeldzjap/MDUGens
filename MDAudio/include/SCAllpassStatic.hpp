#ifndef MD_UGENS_ALLPASS_STATIC_HPP
#define MD_UGENS_ALLPASS_STATIC_HPP

#include "SCAllocator.hpp"
#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "AllpassStatic.hpp"

namespace md_ugens {

    class AllpassStatic : public SCUnit {
    public:
        explicit AllpassStatic();

    private:
        memory::SCPool m_pool;
        memory::SCAllocator<double, memory::SCPool> m_allocator;
        md_audio::AllpassStatic<memory::SCAllocator<double, memory::SCPool>> m_allpass;
        float m_delay_time;
        float m_gain;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_ALLPASS_STATIC_HPP */
