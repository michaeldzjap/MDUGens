#ifndef Lowshelf_hpp
#define Lowshelf_hpp

#include "OnePole.hpp"
#include "Shelving.hpp"

using tpt_filter_ugens::OnePole;
using tpt_filter_ugens::Shelving;

namespace tpt_filter_ugens {

    class Lowshelf : public OnePole, public Shelving {
    public:
        Lowshelf();

    protected:
        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* Lowshelf_hpp */
