#ifndef MD_UGENS_HIGHPASS_FIRST_ORDER_HPP
#define MD_UGENS_HIGHPASS_FIRST_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "HighpassFirstOrder.hpp"

namespace md_ugens {

    class HighpassFirstOrder : public SCUnit {
    public:
        explicit HighpassFirstOrder();

    private:
        md_audio::HighpassFirstOrder m_filter;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_HIGHPASS_FIRST_ORDER_HPP */
