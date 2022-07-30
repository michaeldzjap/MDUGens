#ifndef MD_UGENS_DELAY_HPP
#define MD_UGENS_DELAY_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "Delay.hpp"
#include "types.hpp"

namespace md_ugens {

    class Delay : public SCUnit {
    public:
        explicit Delay();

    private:
        memory::SCPool m_pool;
        md_audio::Delay m_delay;
        float m_delay_time;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_DELAY_HPP */
