#ifndef MD_UGENS_LOWSHELF_FIRST_ORDER_HPP
#define MD_UGENS_LOWSHELF_FIRST_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "LowshelfFirstOrder.hpp"

namespace md_ugens {

    class LowshelfFirstOrder : public SCUnit {
    public:
        explicit LowshelfFirstOrder();

    private:
        md_audio::LowshelfFirstOrder m_filter;

        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_LOWSHELF_FIRST_ORDER_HPP */
