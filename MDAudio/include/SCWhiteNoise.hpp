#ifndef MD_UGENS_WHITE_NOISE_HPP
#define MD_UGENS_WHITE_NOISE_HPP

#include "SC_PlugIn.hpp"
#include "WhiteNoise.hpp"

namespace md_ugens {

    class WhiteNoise : public SCUnit {
    public:
        explicit WhiteNoise();

    private:
        md_audio::WhiteNoise m_noise;

        void next(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_WHITE_NOISE_HPP */
