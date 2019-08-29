#ifndef Tilt2_hpp
#define Tilt2_hpp

#include "TwoPole.hpp"
#include "Shelving.hpp"

using tpt_filter_ugens::TwoPole;
using tpt_filter_ugens::Shelving;

namespace tpt_filter_ugens {

    class Tilt2 : public TwoPole, public Shelving {
    public:
        Tilt2();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* Tilt2_hpp */
