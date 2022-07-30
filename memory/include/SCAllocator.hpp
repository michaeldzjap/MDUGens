#ifndef MD_UGENS_SC_ALLOCATOR_HPP
#define MD_UGENS_SC_ALLOCATOR_HPP

#include "SCPool.hpp"
#include <type_traits>

namespace md_ugens::memory {

    template <typename T, typename Pool>
    class SCAllocator {
    public:
        template <typename U, typename P>
        friend class SCAllocator;

        using value_type = T;
        using pointer = T*;

        using propagate_on_container_copy_assignment = std::true_type;
        using propagate_on_container_move_assignment = std::true_type;
        using propagate_on_container_swap = std::true_type;

        explicit SCAllocator(Pool* pool) : m_pool(pool) {}

        template <typename U, typename P>
        SCAllocator(SCAllocator<U, P> const& that) : m_pool(that.m_pool) {}

        [[nodiscard]] pointer allocate(std::size_t n) {
            return static_cast<pointer>(m_pool->allocate(n * sizeof(T)));
        }

        void deallocate(pointer ptr) noexcept {
            m_pool->deallocate(ptr);
        }

        void deallocate(pointer ptr, std::size_t n [[maybe_unused]]) noexcept {
            deallocate(ptr);
        }

        template <typename U, typename P>
        bool operator==(SCAllocator<U, P> const& that) const {
            return m_pool == that.m_pool;
        }

        template <typename U, typename P>
        bool operator!=(SCAllocator<U, P> const& that) const {
            return m_pool != that.m_pool;
        }

    private:
        Pool* m_pool;
    };

}

#endif /* MD_UGENS_SC_ALLOCATOR_HPP */
