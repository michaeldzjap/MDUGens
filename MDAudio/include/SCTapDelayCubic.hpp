#ifndef MD_UGENS_TAP_DELAY_CUBIC_HPP
#define MD_UGENS_TAP_DELAY_CUBIC_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "TapDelayCubic.hpp"

namespace md_ugens {

    class TapDelayCubic : public SCUnit {
    public:
        explicit TapDelayCubic();

        ~TapDelayCubic();

    private:
        memory::SCPool m_pool;
        md_audio::TapDelayCubic m_delay;
        float* m_delay_times = nullptr;
        float* m_delay_slopes = nullptr;

        void next(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_TAP_DELAY_CUBIC_HPP */
