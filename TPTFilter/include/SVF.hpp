#ifndef SVF_hpp
#define SVF_hpp

#include "TwoPole.hpp"

using tpt_filter_ugens::TwoPole;

namespace tpt_filter_ugens {

    class SVF : public TwoPole {
    public:
        SVF();

    protected:
        void next_aa(int inNumSamples) noexcept;

        void next_ak(int inNumSamples) noexcept;

        void next_ka(int inNumSamples) noexcept;

        void next_kk(int inNumSamples) noexcept;
    };

}

#endif /* SVF_hpp */
