#include "person.hpp"

Person::Person(string name)
{
    m_name = name;
}

string &Person::name()
{
    return m_name;
}