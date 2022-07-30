#ifndef MD_UGENS_ALLPASS_FIRST_ORDER_HPP
#define MD_UGENS_ALLPASS_FIRST_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "AllpassFirstOrder.hpp"

namespace md_ugens {

    class AllpassFirstOrder : public SCUnit {
    public:
        explicit AllpassFirstOrder();

    private:
        md_audio::AllpassFirstOrder m_filter;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_ALLPASS_FIRST_ORDER_HPP */
