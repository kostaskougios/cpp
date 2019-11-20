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

    void forEach(std::function<void(E &)> f)
    {
        for (E *it = begin(); it < end(); f(*it++))
        {
        }
    };

    std::vector<E> toStdVector()
    {
        std::vector<E> v{};
        auto f = [&v](E &e) { v.push_back(e); };
        forEach(f);

        return v;
    };
};
} // namespace fc