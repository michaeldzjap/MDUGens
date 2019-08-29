#ifndef Base_hpp
#define Base_hpp

#include "SC_PlugIn.hpp"

namespace tpt_filter_ugens {

    class Base : public SCUnit {
    public:
        Base();

    protected:
        const double mSr2;
        const double mA;

        inline double computeG(const float freq) noexcept {
            return tan(static_cast<double>(sc_clip(freq, 0.f, mSr2)) * mA);
        }
    };

}

#endif /* Base_hpp */
