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

    std::vector<E> toStdVector()
    {
        std::vector<E> v{};
        auto f = [&v](E &e) { v.push_back(e); };
        this->forEach(f);

        return v;
    };
};

} // namespace fc