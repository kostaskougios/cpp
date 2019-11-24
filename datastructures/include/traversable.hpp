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
    virtual const E *begin() const = 0;
    virtual const E *end() const = 0;

    void forEach(std::function<void(const E &)> f)
    {
        for (const E *it = begin(); it < end(); f(*it++))
            ;
    };

    std::vector<E> toStdVector()
    {
        std::vector<E> v{};
        auto f = [&v](const E &e) { v.push_back(e); };
        this->forEach(f);

        return v;
    };
};

} // namespace fc