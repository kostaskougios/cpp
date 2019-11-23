#pragma once

#include <cstddef>
#include <vector>
#include "traversable.hpp"

namespace fc
{
template <typename E>
class ArrayList : public Traversable<E>
{
private:
    const std::size_t m_sz;
    E *const p;

public:
    ArrayList(E a[], std::size_t sz) : m_sz(sz), p(a){};

    std::size_t size() { return m_sz; };

    E *begin()
    {
        return p;
    };

    E *end()
    {
        return p + m_sz;
    }

    template <typename T>
    ArrayList<T> map(std::function<T(E &)> f)
    {
        T r[m_sz];
        std::size_t i = 0;
        auto ff = [&i, &r, f](E &e) {
            r[i++] = f(e);
        };
        this->forEach(ff);
        return ArrayList<T>(r, m_sz);
    }
};

template <typename E>
bool operator==(ArrayList<E> lhs, ArrayList<E> rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    E *l;
    E *r;
    for (l = lhs.begin(), r = rhs.begin(); l < lhs.end(); l++, r++)
    {
        if (*l != *r)
            return false;
    }
    return true;
}

} // namespace fc