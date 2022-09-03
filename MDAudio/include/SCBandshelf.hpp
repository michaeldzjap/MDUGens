#ifndef MD_UGENS_BANDSHELF_HPP
#define MD_UGENS_BANDSHELF_HPP

#include "SC_PlugIn.hpp"
#include "Bandshelf.hpp"

namespace md_ugens {

    class Bandshelf : public SCUnit {
    public:
        explicit Bandshelf();

    private:
        md_audio::Bandshelf m_filter;

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

#endif /* MD_UGENS_BANDSHELF_HPP */