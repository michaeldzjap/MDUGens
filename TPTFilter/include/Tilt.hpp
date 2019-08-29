#ifndef Tilt_hpp
#define Tilt_hpp

#include "OnePole.hpp"
#include "Shelving.hpp"

using tpt_filter_ugens::OnePole;
using tpt_filter_ugens::Shelving;

namespace tpt_filter_ugens {

    class Tilt : public OnePole, public Shelving {
    public:
        Tilt();

    protected:
        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;
    };

}

#endif /* Tilt_hpp */
