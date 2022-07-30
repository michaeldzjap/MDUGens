#ifndef MD_UGENS_HIGHPASS_SECOND_ORDER_HPP
#define MD_UGENS_HIGHPASS_SECOND_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "HighpassSecondOrder.hpp"

namespace md_ugens {

    class HighpassSecondOrder : public SCUnit {
    public:
        explicit HighpassSecondOrder();

    private:
        md_audio::HighpassSecondOrder m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_HIGHPASS_SECOND_ORDER_HPP */