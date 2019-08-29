#ifndef Highpass_hpp
#define Highpass_hpp

#include "OnePole.hpp"

using tpt_filter_ugens::OnePole;

namespace tpt_filter_ugens {

    class Highpass : public OnePole {
    public:
        Highpass();

    protected:
        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* Highpass_hpp */
