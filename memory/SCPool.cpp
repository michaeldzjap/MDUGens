#include "SCPool.hpp"

using md_ugens::memory::SCPool;

SCPool::SCPool(World* world) : m_world(world) {}

void* SCPool::allocate(std::size_t size) {
    return RTAlloc(m_world, size);
}

void SCPool::deallocate(void* ptr) noexcept {
    RTFree(m_world, ptr);
}
