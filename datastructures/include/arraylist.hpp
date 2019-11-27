#pragma once

#include <cstddef>
#include <vector>
#include <initializer_list>
#include "traversable.hpp"

namespace fc
{
template <typename E>
class ArrayList : public Traversable<E>
{
private:
    const std::size_t m_sz;
    const E *const p;

    const E *createArray(std::initializer_list<E> const &a)
    {
        E *newArray = new E[a.size()];
        E *it = newArray;
        for (E e : a)
        {
            *it++ = e;
        }
        return newArray;
    }

    const E *createArray(E a[], const std::size_t sz)
    {
        E *newArray = new E[sz];
        for (std::size_t i = 0; i < sz; i++)
        {
            newArray[i] = a[i];
        }
        return newArray;
    }

public:
    ArrayList(E a[], std::size_t sz) : m_sz(sz), p(createArray(a, sz)){};
    ArrayList(std::initializer_list<E> const &a) : m_sz(a.size()), p(createArray(a)){};

    ~ArrayList()
    {
        delete[] p;
    };

    std::size_t size() const { return m_sz; };

    const E *begin() const
    {
        const E *e = p;
        return e;
    };

    const E *end() const
    {
        const E *e = p;
        return e + m_sz;
    }

    template <typename T>
    ArrayList<T> map(std::function<T(const E &)> f)
    {
        T r[m_sz];
        unsigned int i = 0;
        auto ff = [&i, &r, &f](const E &e) {
            r[i++] = f(e);
        };
        this->forEach(ff);
        return ArrayList<T>(r, m_sz);
    }
};

template <typename E>
bool operator==(const ArrayList<E> &lhs, const ArrayList<E> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    const E *l;
    const E *r;
    for (l = lhs.begin(), r = rhs.begin(); l < lhs.end(); l++, r++)
    {
        if (*l != *r)
        {
            // std::cout << *l << "->" << *r << std::endl;
            return false;
        }
    }
    return true;
}

} // namespace fc