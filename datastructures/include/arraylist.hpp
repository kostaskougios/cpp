#pragma once

#include <cstddef>

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

    E &values()
    {
        return p;
    };

    // ArrayList(std::initializer_list<T> values);
};
} // namespace fc