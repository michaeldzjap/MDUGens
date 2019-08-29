#ifndef Bandshelf_hpp
#define Bandshelf_hpp

#include "TwoPole.hpp"
#include "Shelving.hpp"

using tpt_filter_ugens::TwoPole;
using tpt_filter_ugens::Shelving;

namespace tpt_filter_ugens {

    class Bandshelf : public TwoPole, public Shelving {
    public:
        Bandshelf();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* Bandshelf_hpp */
