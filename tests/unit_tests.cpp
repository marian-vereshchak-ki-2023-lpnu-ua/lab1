#include <gtest/gtest.h>
#include "../math_operations.h"

TEST(MathOperationsTest, AddsTwoPositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathOperationsTest, AddsNegativeAndPositiveNumbers) {
    EXPECT_EQ(add(-2, 5), 3);
}

TEST(MathOperationsTest, AddsZeroAndZero) {
    EXPECT_EQ(add(0, 0), 0);
}

TEST(MathOperationsTest, AddsLargeNumbers) {
    EXPECT_EQ(add(1000000, 2000000), 3000000);
}
