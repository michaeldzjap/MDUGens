#ifndef MD_UGENS_VARIABLE_DELAY_HPP
#define MD_UGENS_VARIABLE_DELAY_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "VariableDelay.hpp"
#include "types.hpp"

namespace md_ugens {

    class VariableDelay : public SCUnit {
    public:
        explicit VariableDelay();

    private:
        memory::SCPool m_pool;
        md_audio::VariableDelay m_delay;
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
