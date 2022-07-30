#ifndef MD_UGENS_TAP_DELAY_HPP
#define MD_UGENS_TAP_DELAY_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "TapDelay.hpp"

namespace md_ugens {

    class TapDelay : public SCUnit {
    public:
        explicit TapDelay();

        ~TapDelay();

    private:
        memory::SCPool m_pool;
        md_audio::TapDelay m_delay;
        float* m_delay_times = nullptr;
        float* m_delay_slopes = nullptr;

        void next(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_TAP_DELAY_HPP */
