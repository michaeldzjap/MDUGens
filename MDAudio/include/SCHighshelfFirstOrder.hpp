#ifndef MD_UGENS_HIGHSHELF_FIRST_ORDER_HPP
#define MD_UGENS_HIGHSHELF_FIRST_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "HighshelfFirstOrder.hpp"

namespace md_ugens {

    class HighshelfFirstOrder : public SCUnit {
    public:
        explicit HighshelfFirstOrder();

    private:
        md_audio::HighshelfFirstOrder m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_HIGHSHELF_FIRST_ORDER_HPP */
