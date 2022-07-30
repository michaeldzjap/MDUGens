#ifndef MD_AUDIO_SC_POOL_HPP
#define MD_AUDIO_SC_POOL_HPP

#include "registration.hpp"
#include "SC_PlugIn.hpp"
#include <cstdint>

namespace md_ugens::memory {

    class SCPool {
    public:
        explicit SCPool(World* world);

        void* ASSUME_ALIGNED(64) allocate(std::size_t size);

        void deallocate(void* ptr) noexcept;

    private:
        World* m_world;
    };

}

#endif /* MD_AUDIO_SC_POOL_HPP */
