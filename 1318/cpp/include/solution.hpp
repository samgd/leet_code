#pragma once

class Solution {
 public:
  int minFlips(int a, int b, int c) {
    return (__builtin_popcount(c & (~a & ~b)) + __builtin_popcount(~c & a) +
            __builtin_popcount(~c & b));
  }
};
