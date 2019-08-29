#ifndef Highpass2_hpp
#define Highpass2_hpp

#include "TwoPole.hpp"

using tpt_filter_ugens::TwoPole;

namespace tpt_filter_ugens {

    class Highpass2 : public TwoPole {
    public:
        Highpass2();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* Highpass2_hpp */
