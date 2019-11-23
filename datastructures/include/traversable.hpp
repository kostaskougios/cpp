#pragma once

#include <cstddef>
#include <functional>
#include <vector>

namespace fc
{
template <typename E>
class Traversable
{
public:
    virtual E *begin() const = 0;
    virtual E *end() const = 0;

    void forEach(std::function<void(E &)> f)
    {
        for (E *it = begin(); it < end(); f(*it++))
            ;
    };

    std::vector<E> toStdVector()
    {
        std::vector<E> v{};
        auto f = [&v](E &e) { v.push_back(e); };
        this->forEach(f);

        return v;
    };
};

} // namespace fc