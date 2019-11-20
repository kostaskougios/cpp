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

    void forEach(std::function<void(E &)> f)
    {
        E *it = p;
        for (std::size_t i = 0; i < m_sz; i++)
        {
            f(*it);
            it++;
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