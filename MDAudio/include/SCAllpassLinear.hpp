#ifndef MD_UGENS_ALLPASS_LINEAR_HPP
#define MD_UGENS_ALLPASS_LINEAR_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "AllpassLinear.hpp"
#include "types.hpp"

namespace md_ugens {

    class AllpassLinear : public SCUnit {
    public:
        explicit AllpassLinear();

    private:
        memory::SCPool m_pool;
        md_audio::AllpassLinear m_allpass;
        float m_delay_time;
        float m_gain;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_ALLPASS_LINEAR_HPP */
