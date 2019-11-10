#include "person.hpp"

using std::string;
using std::hash;

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