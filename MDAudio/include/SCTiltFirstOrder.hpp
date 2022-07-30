#ifndef MD_UGENS_TILT_FIRST_ORDER_HPP
#define MD_UGENS_TILT_FIRST_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "TiltFirstOrder.hpp"

namespace md_ugens {

    class TiltFirstOrder : public SCUnit {
    public:
        explicit TiltFirstOrder();

    private:
        md_audio::TiltFirstOrder m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_TILT_FIRST_ORDER_HPP */