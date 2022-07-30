#ifndef MD_UGENS_LOWSHELF_SECOND_ORDER_HPP
#define MD_UGENS_LOWSHELF_SECOND_ORDER_HPP

#include "SC_PlugIn.hpp"
#include "LowshelfSecondOrder.hpp"

namespace md_ugens {

    class LowshelfSecondOrder : public SCUnit {
    public:
        explicit LowshelfSecondOrder();

    private:
        md_audio::LowshelfSecondOrder m_filter;

        void next_aaa(int inNumSamples) noexcept;

        void next_aka(int inNumSamples) noexcept;

        void next_aak(int inNumSamples) noexcept;

        void next_kaa(int inNumSamples) noexcept;

        void next_akk(int inNumSamples) noexcept;

        void next_kak(int inNumSamples) noexcept;

        void next_kka(int inNumSamples) noexcept;

        void next_kkk(int inNumSamples) noexcept;
    };

}

#endif /* MD_UGENS_LOWSHELF_SECOND_ORDER_HPP */