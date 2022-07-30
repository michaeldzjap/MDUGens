#ifndef MD_UGENS_PHASOR_HPP
#define MD_UGENS_PHASOR_HPP

#include "SC_PlugIn.hpp"
#include "Phasor.hpp"

namespace md_ugens {

    class Phasor : public SCUnit {
    public:
        explicit Phasor();

    private:
        md_audio::Phasor m_phasor;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_PHASOR_HPP */
