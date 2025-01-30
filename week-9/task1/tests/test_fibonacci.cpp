#include <gtest/gtest.h>
#include "../include/fibonacci.hpp"


TEST(FibonacciTest, BaseCases) {
    EXPECT_EQ(fibonacci_classic(0), 0);
    EXPECT_EQ(fibonacci_classic(1), 1);
    EXPECT_EQ(fibonacci_optimized(0), 0);
    EXPECT_EQ(fibonacci_optimized(1), 1);
}


TEST(FibonacciTest, SmallValues) {
    EXPECT_EQ(fibonacci_classic(2), 1);
    EXPECT_EQ(fibonacci_classic(3), 2);
    EXPECT_EQ(fibonacci_classic(4), 3);
    EXPECT_EQ(fibonacci_classic(5), 5);
    
    EXPECT_EQ(fibonacci_optimized(2), 1);
    EXPECT_EQ(fibonacci_optimized(3), 2);
    EXPECT_EQ(fibonacci_optimized(4), 3);
    EXPECT_EQ(fibonacci_optimized(5), 5);
}


TEST(FibonacciTest, LargeValues) {
    EXPECT_EQ(fibonacci_classic(10), 55);
    EXPECT_EQ(fibonacci_classic(20), 6765);
    EXPECT_EQ(fibonacci_optimized(10), 55);
    EXPECT_EQ(fibonacci_optimized(20), 6765);
}


TEST(FibonacciTest, NegativeValues) {
    EXPECT_THROW(fibonacci_classic(-1), std::invalid_argument);
    EXPECT_THROW(fibonacci_optimized(-1), std::invalid_argument);
}


TEST(FibonacciTest, VeryLargeValues) {
    EXPECT_EQ(fibonacci_optimized(50), 12586269025);
    EXPECT_EQ(fibonacci_optimized(60), 1548008755920);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}









