#ifndef Lowpass_hpp
#define Lowpass_hpp

#include "OnePole.hpp"

using tpt_filter_ugens::OnePole;

namespace tpt_filter_ugens {

    class Lowpass : public OnePole {
    public:
        Lowpass();

    protected:
        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* Lowpass_hpp */
