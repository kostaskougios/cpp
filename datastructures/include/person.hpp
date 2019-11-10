#pragma once

#include <string>

using namespace std;

class Person
{
private:
    string m_name = "";

public:
    Person() : Person("anonymous"){};
    Person(string);

    string &name();

    string toString();
};

bool operator==(Person, Person);
