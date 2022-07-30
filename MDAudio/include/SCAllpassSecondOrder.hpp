#ifndef MD_UGENS_ALLPASS_SECOND_ORDER_HPP
#define MD_UGENS_ALLPASS_SECOND_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "AllpassSecondOrder.hpp"

namespace md_ugens {

    class AllpassSecondOrder : public SCUnit {
    public:
        explicit AllpassSecondOrder();

    private:
        md_audio::AllpassSecondOrder m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_ALLPASS_SECOND_ORDER_HPP */