#include <gtest/gtest.h>
#include "arraylist.hpp"

using namespace std;

TEST(ARRAYLIST_DEFAULT_CONSTRUCTOR, Positive)
{
    string data[] = {"Kostas", "Kougios"};
    fc::ArrayList<string> a(data, 2);

    string &values = a.values();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}