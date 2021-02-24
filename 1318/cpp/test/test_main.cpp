#include "gtest/gtest.h"
#include "solution.hpp"

TEST(SolutionTest, Example1) {
  Solution s;
  ASSERT_EQ(s.minFlips(2, 6, 5), 3);
}

TEST(SolutionTest, Example2) {
  Solution s;
  ASSERT_EQ(s.minFlips(4, 2, 7), 1);
}

TEST(SolutionTest, Example3) {
  Solution s;
  ASSERT_EQ(s.minFlips(1, 2, 3), 0);
}
