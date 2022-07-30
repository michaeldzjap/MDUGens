#ifndef MD_UGENS_HANN_OSCILLATOR_HPP
#define MD_UGENS_HANN_OSCILLATOR_HPP

#include "SC_PlugIn.hpp"
#include "HannOscillator.hpp"

namespace md_ugens {

    class HannOscillator : public SCUnit {
    public:
        explicit HannOscillator();

    private:
        md_audio::HannOscillator m_osc;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_HANN_OSCILLATOR_HPP */
