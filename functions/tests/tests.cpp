#include "whattotest.hpp"
#include <gtest/gtest.h>
#include <immer/vector.hpp>
#include <immer/algorithm.hpp>

template <typename Collection, typename Unop>
Collection map(Collection col, Unop op)
{
    return immer::copy(col.begin(), col.end(), op);
}

TEST(Function_Declaration, Positive)
{
    auto a = immer::vector<int>{1, 5, 10};

    auto inc = [](int i) { return i + 1; };

    auto expect = immer::vector<int>{2, 6, 11};
    auto actual = map(a, inc);
    ASSERT_EQ(actual, expect);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}