#ifndef MD_UGENS_LOWPASS_SECOND_ORDER_HPP
#define MD_UGENS_LOWPASS_SECOND_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "LowpassSecondOrder.hpp"

namespace md_ugens {

    class LowpassSecondOrder : public SCUnit {
    public:
        explicit LowpassSecondOrder();

    private:
        md_audio::LowpassSecondOrder m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_LOWPASS_SECOND_ORDER_HPP */