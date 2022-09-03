#ifndef MD_UGENS_BANDSTOP_HPP
#define MD_UGENS_BANDSTOP_HPP

#include "SC_PlugIn.hpp"
#include "Bandstop.hpp"

namespace md_ugens {

    class Bandstop : public SCUnit {
    public:
        explicit Bandstop();

    private:
        md_audio::Bandstop m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_BANDSTOP_HPP */