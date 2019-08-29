#ifndef Allpass_hpp
#define Allpass_hpp

#include "OnePole.hpp"

using tpt_filter_ugens::OnePole;

namespace tpt_filter_ugens {

    class Allpass : public OnePole {
    public:
        Allpass();

    protected:
        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* Allpass_hpp */
