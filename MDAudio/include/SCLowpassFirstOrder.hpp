#ifndef MD_UGENS_LOWPASS_FIRST_ORDER_HPP
#define MD_UGENS_LOWPASS_FIRST_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "LowpassFirstOrder.hpp"

namespace md_ugens {

    class LowpassFirstOrder : public SCUnit {
    public:
        explicit LowpassFirstOrder();

    private:
        md_audio::LowpassFirstOrder m_filter;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_LOWPASS_FIRST_ORDER_HPP */
