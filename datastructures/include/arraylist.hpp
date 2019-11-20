#pragma once

#include <cstddef>
#include <vector>

namespace fc
{
template <typename E>
class ArrayList
{
private:
    const std::size_t m_sz;
    const E *p;

public:
    ArrayList(E a[], std::size_t sz) : m_sz(sz)
    {
        p = a;
    };

    std::vector<E> values()
    {
        std::vector<E> v{};
        auto it = p;
        return v;
    };

    // ArrayList(std::initializer_list<T> values);
};
} // namespace fc