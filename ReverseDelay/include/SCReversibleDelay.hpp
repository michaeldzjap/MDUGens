#ifndef SCReversibleDelay_hpp
#define SCReversibleDelay_hpp

#include "ReversibleDelay.hpp"
#include "SCAllocator.hpp"
#include "SCPool.hpp"
#include "SC_PlugIn.hpp"

namespace md_ugens {

    class ReversibleDelay : public SCUnit {
    public:
        ReversibleDelay();

    private:
        memory::SCPool m_pool;
        memory::SCAllocator<md_audio::MdFloat, memory::SCPool> m_allocator;
        md_audio::ReversibleDelay<memory::SCAllocator<md_audio::MdFloat, memory::SCPool>, 2> m_reversible_delay;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* SCReversibleDelay_hpp */
