#ifndef MD_UGENS_BANDPASS_HPP
#define MD_UGENS_BANDPASS_HPP

#include "SC_PlugIn.hpp"
#include "Bandpass.hpp"

namespace md_ugens {

    class Bandpass : public SCUnit {
    public:
        explicit Bandpass();

    private:
        md_audio::Bandpass m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_BANDPASS_HPP */