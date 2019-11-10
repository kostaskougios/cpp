#include <gtest/gtest.h>
#include "person.hpp"
#include <immer/map.hpp>

using namespace model;

TEST(PERSON_NAME_TEST, Positive) {
    Person p("Kostas");
    ASSERT_EQ(p.name(),"Kostas");
}

TEST(MAP_OF_PERSON_VALUE, Positive) {
    auto v0 = immer::map<std::string, Person>().set("kostas", Person("Kostas"));

    ASSERT_EQ(v0["kostas"],Person("Kostas"));
}

TEST(MAP_OF_PERSON_KEY, Positive) {
    auto v0 = immer::map<Person, int>();
    auto v1 = v0.set(Person("kostas"),5).set(Person("nick"),6);

    ASSERT_EQ(v1[Person("kostas")],5);
    ASSERT_EQ(v1[Person("nick")],6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}