#pragma once

#include <algorithm>
#include <set>
#include <vector>

class Window {
 public:
  // Extracts `last_elem` from the Window and inserts `new_elem`. Returns the
  // maximum value in the Window after the removal and insertion has
  // completed.
  inline int insert(int last_elem, int new_elem) {
    elements.extract(last_elem);
    elements.insert(new_elem);
    return max();
  }

  // Inserts `new_elem` into the Window.
  inline void insert(int new_elem) { elements.insert(new_elem); }

  // Returns the maximum value in the Window.
  inline int max() const { return *elements.rbegin(); }

 private:
  std::multiset<int> elements;
};

class Solution {
 public:
  // maxSlidingWindow slides a window of size k over nums and returns a
  // vector containing the maximum values in each window position.
  //
  // This implementation is O(nlogk) but likely has a higher constant than
  // the naive O(nk) implementation (where `n = nums.size()`).
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> results;
    // Problem constraints specify: 1 <= k <= nums.length
    // This means we can assume results will contain this many elements.
    results.reserve(static_cast<int>(nums.size()) - k + 1);

    Window w;

    // Prime window with k values before finding first maximum.
    for (int i = 0; i < k; i++) {
      w.insert(nums[i]);
    }
    results.push_back(w.max());

    // Iterate over all remaining window positions (remove last, add new,
    // push new maximum to results).
    for (int i = k; i < static_cast<int>(nums.size()); i++) {
      results.push_back(w.insert(nums[i - k], nums[i]));
    }

    return results;
  }
};
