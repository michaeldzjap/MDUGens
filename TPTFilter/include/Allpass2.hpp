#ifndef Allpass2_hpp
#define Allpass2_hpp

#include "TwoPole.hpp"

using tpt_filter_ugens::TwoPole;

namespace tpt_filter_ugens {

    class Allpass2 : public TwoPole {
    public:
        Allpass2();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* Allpass2_hpp */
