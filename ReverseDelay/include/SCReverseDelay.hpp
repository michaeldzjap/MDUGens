#ifndef SCReverseDelay_hpp
#define SCReverseDelay_hpp

// #include "ReverseDelay.hpp"
#include "SCAllocator.hpp"
#include "SCPool.hpp"
#include "SC_PlugIn.hpp"
#include "types.hpp"

namespace md_ugens {

    class ReverseDelay : public SCUnit {
    public:
        ReverseDelay();

        ~ReverseDelay();

    private:
        memory::SCPool m_pool;
        memory::SCAllocator<md_audio::MdFloat, memory::SCPool> m_allocator;
        md_audio::MdFloat* m_memory = nullptr;
        // md_audio::ReverseDelay<memory::SCAllocator<md_audio::MdFloat, memory::SCPool>, 2> m_reverse_delay;

        void next_a(int inNumSamples) noexcept;

        void next_k(int inNumSamples) noexcept;

        void clear(int inNumSamples);
    };

}

#endif /* SCReverseDelay_hpp */
