#ifndef Shelving_hpp
#define Shelving_hpp

#include "SC_PlugIn.hpp"
#include <cmath>

namespace tpt_filter_ugens {

    class Shelving {
    protected:
        inline double computeM2(float gain) noexcept {
            return std::pow(10., static_cast<double>(gain) / 20.);
        }
    };

}

#endif /* Shelving_hpp */
