#pragma once

#include <string>

namespace model
{

class Person
{
private:
    std::string m_name = "";

public:
    Person() : Person("anonymous"){};
    Person(std::string);

    std::string &name();

    std::string toString();
};

bool operator==(Person, Person);

} // namespace model
