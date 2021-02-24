#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findMaxLength(std::vector<int> &nums) {
    auto count = 0;
    auto max = 0;
    std::unordered_map<int, int> counts{{0, 0}};

    for (auto i = 1; i < 1 + static_cast<int>(nums.size()); i++) {
      if (nums[i - 1] == 0) {
        count--;
      } else {
        count++;
      }

      if (counts.find(count) != counts.end()) {
        auto len = i - counts.at(count);
        max = std::max(max, len);
      } else {
        counts[count] = i;
      }
    }

    return max;
  }
};
