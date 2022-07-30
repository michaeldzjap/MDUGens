#ifndef MD_UGENS_REVERSIBLE_DELAY_HPP
#define MD_UGENS_REVERSIBLE_DELAY_HPP

#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "ReversibleDelay.hpp"
#include "types.hpp"

namespace md_ugens {

    class ReversibleDelay : public SCUnit {
    public:
        explicit ReversibleDelay();

    private:
        memory::SCPool m_pool;
        md_audio::ReversibleDelay m_reverser;
        float m_size;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* MD_UGENS_REVERSIBLE_DELAY_HPP */
