#include <gtest/gtest.h>
#include "person.hpp"
#include <immer/map.hpp>

TEST(PERSON_NAME_TEST, PositiveNos) {
    Person p("Kostas");
    ASSERT_EQ(p.name(),"Kostas");
}

TEST(map_of_person, Positive) {
    auto v0 = immer::map<std::string, Person>();
    auto v1 = v0.set("kostas", Person("Kostas"));

    ASSERT_EQ(v1["kostas"],Person("Kostas"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}