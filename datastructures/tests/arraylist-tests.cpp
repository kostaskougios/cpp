#include <gtest/gtest.h>
#include <vector>
#include <array>
#include "traversable.hpp"
#include "arraylist.hpp"
#include <iostream>

TEST(ArrayList, toStdVector)
{
    std::string data[] = {"Kostas", "Kougios"};
    fc::ArrayList<std::string> a(data, 2);

    auto actual = a.toStdVector();
    auto expected = std::vector<std::string>{"Kostas", "Kougios"};
    ASSERT_EQ(actual, expected);
}

TEST(ArrayList, toStdVectorTwice)
{
    std::string data[] = {"Kostas", "Kougios"};
    fc::ArrayList<std::string> a(data, 2);

    auto expected = std::vector<std::string>{"Kostas", "Kougios"};

    ASSERT_EQ(a.toStdVector(), expected);
    ASSERT_EQ(a.toStdVector(), expected);
}

TEST(ArrayList, map)
{
    std::string data[] = {"1", "2"};
    fc::ArrayList<std::string> a(data, 2);

    auto actual = a.map<int>([](std::string &s) {
        return std::stoi(s);
    });
    int e[] = {1, 2};
    fc::ArrayList<int> expected(e, 2);

    ASSERT_EQ(actual, expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}