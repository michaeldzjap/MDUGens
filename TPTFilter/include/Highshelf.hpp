#ifndef Highshelf_hpp
#define Highshelf_hpp

#include "OnePole.hpp"
#include "Shelving.hpp"

using tpt_filter_ugens::OnePole;
using tpt_filter_ugens::Shelving;

namespace tpt_filter_ugens {

    class Highshelf : public OnePole, public Shelving {
    public:
        Highshelf();

    protected:
        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* Highshelf_hpp */
