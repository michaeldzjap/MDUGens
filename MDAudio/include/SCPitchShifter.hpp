#ifndef MD_UGENS_PITCH_SHIFTER_HPP
#define MD_UGENS_PITCH_SHIFTER_HPP

#include "SCAllocator.hpp"
#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "PitchShifter.hpp"

namespace md_ugens {

    class PitchShifter : public SCUnit {
    public:
        explicit PitchShifter();

    private:
        memory::SCPool m_pool;
        memory::SCAllocator<double, memory::SCPool> m_allocator;
        md_audio::PitchShifter<memory::SCAllocator<double, memory::SCPool>> m_shifter;
        float m_size;
        float m_transposition;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_PITCH_SHIFTER_HPP */
