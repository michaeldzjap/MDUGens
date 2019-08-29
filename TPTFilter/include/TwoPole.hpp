#ifndef TwoPole_hpp
#define TwoPole_hpp

#include "Base.hpp"

using tpt_filter_ugens::Base;

namespace tpt_filter_ugens {

    class TwoPole : public Base {
    public:
        TwoPole();

    protected:
        double mS1;
        double mS2;

        inline double compute2r(float r) noexcept {
            r = sc_max(r, 0.f);

            return static_cast<double>(r + r);
        }

        inline double computeD(double r2, double g) noexcept {
            return 1. / (1. + r2 * g + g * g);
        }
    };

}

#endif /* TwoPole_hpp */
