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

    std::vector<E> toStdVector()
    {
        std::vector<E> v{};
        auto it = p;
        for (std::size_t i = 0; i < m_sz; i++)
        {
            v.push_back(*it);
            it++;
        }
        return v;
    };

    // ArrayList(std::initializer_list<T> values);
};
} // namespace fc