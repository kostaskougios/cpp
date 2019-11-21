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
    ArrayList(E a[], std::size_t sz) : p(a), m_sz(sz){};

    E *begin()
    {
        return p;
    };

    E *end()
    {
        return p + m_sz;
    }

    std::vector<E> toStdVector()
    {
        std::vector<E> v{};
        auto f = [&v](E &e) { v.push_back(e); };
        this->forEach(f);

        return v;
    };
};
} // namespace fc