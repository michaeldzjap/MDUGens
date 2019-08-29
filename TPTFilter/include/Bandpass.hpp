#ifndef Bandpass_hpp
#define Bandpass_hpp

#include "TwoPole.hpp"

using tpt_filter_ugens::TwoPole;

namespace tpt_filter_ugens {

    /**
     * This is actually the normalised bandpass variant.
     */
    class Bandpass : public TwoPole {
    public:
        Bandpass();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* Bandpass_hpp */
