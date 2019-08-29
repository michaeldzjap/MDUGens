#ifndef OnePole_hpp
#define OnePole_hpp

#include "Base.hpp"

using tpt_filter_ugens::Base;

namespace tpt_filter_ugens {

    class OnePole : public Base {
    public:
        OnePole();

    protected:
        double mS;
    };

}

#endif /* OnePole_hpp */
