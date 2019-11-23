#include "traversable.hpp"

namespace fc
{
template <typename E>
void Traversable<E>::forEach(std::function<void(E &)> f)
{
    for (E *it = begin(); it < end(); f(*it++))
    {
    }
}

template <typename E>
std::vector<E> Traversable<E>::toStdVector()
{
    std::vector<E> v{};
    auto f = [&v](E &e) { v.push_back(e); };
    this->forEach(f);

    return v;
};

} // namespace fc