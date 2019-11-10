#include "person.hpp"

using std::hash;
using std::string;

namespace model
{
Person::Person(string name)
{
    m_name = name;
}

string &Person::name()
{
    return m_name;
}

string Person::toString()
{
    return "Person(" + name() + ")";
}

bool operator==(Person lhs, Person rhs)
{
    return lhs.name() == rhs.name();
}
} // namespace model

std::size_t std::hash<model::Person>::operator()(model::Person p) const
{
    return std::hash<std::string>()(p.name());
}
