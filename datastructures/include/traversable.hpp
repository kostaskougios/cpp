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
    virtual E *begin() = 0;
    virtual E *end() = 0;

    void forEach(std::function<void(E &)>);

    std::vector<E> toStdVector();
};

} // namespace fc