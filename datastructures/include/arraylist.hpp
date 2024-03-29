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

    template <typename A>
    const E *createArray(A &a, const std::size_t sz)
    {
        E *newArray = new E[sz];
        int i = 0;
        for (E v : a)
        {
            newArray[i++] = v;
        }
        return newArray;
    }

public:
    ArrayList(E a[], std::size_t sz) : m_sz(sz), p(a){};
    ArrayList(std::initializer_list<E> const &a) : m_sz(a.size()), p(createArray(a, a.size())){};

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
        T *r = new T[m_sz];
        T *c = r;
        this->forEach([&r, &f](const E &e) {
            *r = f(e);
            r++;
        });
        return ArrayList<T>(c, m_sz);
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
            return false;
        }
    }
    return true;
}

template <typename E>
bool operator==(const ArrayList<E *> &lhs, const ArrayList<E *> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    const E *const *l;
    const E *const *r;
    for (l = lhs.begin(), r = rhs.begin(); l < lhs.end(); l++, r++)
    {
        if (**l != **r)
        {
            return false;
        }
    }
    return true;
}

} // namespace fc