#include <gtest/gtest.h>
#include "arraylist.hpp"
#include <vector>
#include <array>

TEST(ArrayList, toStdVector)
{
    std::string data[] = {"Kostas", "Kougios"};
    fc::ArrayList<std::string> a(data, 2);

    auto actual = a.toStdVector();
    auto expected = std::vector<std::string>{"Kostas", "Kougios"};
    ASSERT_EQ(actual, expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}