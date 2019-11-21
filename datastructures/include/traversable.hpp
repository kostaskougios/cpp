#pragma once

namespace fc
{
template <typename E>
class Traversable
{
public:
    virtual E *begin();
    virtual E *end();

    void forEach(std::function<void(E &)> f)
    {
        for (E *it = begin(); it < end(); f(*it++))
        {
        }
    };
};

} // namespace fc