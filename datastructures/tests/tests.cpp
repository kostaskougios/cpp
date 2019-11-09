#include <gtest/gtest.h>
#include "person.hpp"

TEST(PERSON_NAME_TEST, PositiveNos) {
    Person p("Kostas");
    ASSERT_EQ(p.name(),"Kostas");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}