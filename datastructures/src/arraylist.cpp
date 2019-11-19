#include "arraylist.hpp"

namespace fc
{

template <typename E>
E &ArrayList<E>::values()
{
    return p;
}

} // namespace fc