#ifndef MD_UGENS_SINE_SHAPER_HPP
#define MD_UGENS_SINE_SHAPER_HPP

#include "SC_PlugIn.hpp"
#include "SineShaper.hpp"

namespace md_ugens {

    class SineShaper : public SCUnit {
    public:
        explicit SineShaper();

    private:
        md_audio::SineShaper m_shaper;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_SINE_SHAPER_HPP */
