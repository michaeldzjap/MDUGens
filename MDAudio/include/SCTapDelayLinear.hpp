#ifndef MD_UGENS_TAP_DELAY_LINEAR_HPP
#define MD_UGENS_TAP_DELAY_LINEAR_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "TapDelayLinear.hpp"

namespace md_ugens {

    class TapDelayLinear : public SCUnit {
    public:
        explicit TapDelayLinear();

        ~TapDelayLinear();

    private:
        memory::SCPool m_pool;
        md_audio::TapDelayLinear m_delay;
        float* m_delay_times = nullptr;
        float* m_delay_slopes = nullptr;

        void next(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_TAP_DELAY_LINEAR_HPP */
