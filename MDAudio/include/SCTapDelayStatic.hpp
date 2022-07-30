#ifndef MD_UGENS_TAP_DELAY_STATIC_HPP
#define MD_UGENS_TAP_DELAY_STATIC_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "TapDelayStatic.hpp"

namespace md_ugens {

    class TapDelayStatic : public SCUnit {
    public:
        explicit TapDelayStatic();

    private:
        memory::SCPool m_pool;
        md_audio::TapDelayStatic m_delay;

        void next(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_TAP_DELAY_STATIC_HPP */
