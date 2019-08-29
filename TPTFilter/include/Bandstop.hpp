#ifndef Bandstop_hpp
#define Bandstop_hpp

#include "TwoPole.hpp"

using tpt_filter_ugens::TwoPole;

namespace tpt_filter_ugens {

    class Bandstop : public TwoPole {
    public:
        Bandstop();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* Bandstop_hpp */
