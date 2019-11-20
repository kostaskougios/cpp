#include <gtest/gtest.h>
#include "arraylist.hpp"
#include <vector>
#include <array>

TEST(ARRAYLIST_DEFAULT_CONSTRUCTOR, Positive)
{
    std::string data[] = {"Kostas", "Kougios"};
    fc::ArrayList<std::string> a(data, 2);

    auto v = a.values();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}