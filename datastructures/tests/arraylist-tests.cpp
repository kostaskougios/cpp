#include <gtest/gtest.h>
#include <vector>
#include <array>
#include "traversable.hpp"
#include "arraylist.hpp"
#include <iostream>
#include <memory>

TEST(ArrayList, toStdVector)
{
    fc::ArrayList<std::string> a{"Kostas", "Kougios"};

    auto actual = a.toStdVector();
    auto expected = std::vector<std::string>{"Kostas", "Kougios"};
    ASSERT_EQ(actual, expected);
}

TEST(ArrayList, toStdVectorTwice)
{
    fc::ArrayList<std::string> a{"Kostas", "Kougios"};

    auto expected = std::vector<std::string>{"Kostas", "Kougios"};

    ASSERT_EQ(a.toStdVector(), expected);
    ASSERT_EQ(a.toStdVector(), expected);
}

TEST(ArrayList, initializer_list_init)
{
    fc::ArrayList<std::string> expected{"1", "2"};
    fc::ArrayList<std::string> actual{"1", "2"};

    ASSERT_EQ(expected, actual);
}

TEST(ArrayList, map)
{
    fc::ArrayList<std::string> a{"1", "2"};

    auto actual = a.map<int>([](const std::string &s) {
        return std::stoi(s);
    });

    // make sure original list not modified
    fc::ArrayList<std::string> expected1{"1", "2"};
    ASSERT_EQ(a, expected1);

    // check modified list
    fc::ArrayList<int> expected2{1, 2};

    ASSERT_EQ(actual, expected2);
}

auto createArray()
{
    auto s1 = new std::string("1");
    auto s2 = new std::string("2");
    return new fc::ArrayList<std::string *>{s1, s2};
};

TEST(ArrayList, memory)
{
    auto actual = createArray();
    auto *expected = new fc::ArrayList<std::string *>{new std::string("1"), new std::string("2")};
    ASSERT_EQ(*actual, *expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}