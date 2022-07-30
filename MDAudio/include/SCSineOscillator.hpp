#ifndef MD_UGENS_SINE_OSCILLATOR_HPP
#define MD_UGENS_SINE_OSCILLATOR_HPP

#include "SC_PlugIn.hpp"
#include "SineOscillator.hpp"

namespace md_ugens {

    class SineOscillator : public SCUnit {
    public:
        explicit SineOscillator();

    private:
        md_audio::SineOscillator m_osc;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_SINE_OSCILLATOR_HPP */
