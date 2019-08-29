#ifndef Lowshelf2_hpp
#define Lowshelf2_hpp

#include "TwoPole.hpp"
#include "Shelving.hpp"

using tpt_filter_ugens::TwoPole;
using tpt_filter_ugens::Shelving;

namespace tpt_filter_ugens {

    class Lowshelf2 : public TwoPole, public Shelving {
    public:
        Lowshelf2();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* Lowshelf2_hpp */
