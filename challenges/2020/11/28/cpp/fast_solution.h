#pragma once

#include <queue>
#include <vector>

class Solution {
 public:
  // maxSlidingWindow slides a window of size k over nums and returns a
  // vector containing the maximum values in each window position.
  //
  // This implementation is O(n).
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> results;
    // Problem constraints specify: 1 <= k <= nums.length
    // This means we can assume results will contain this many elements.
    results.reserve(static_cast<int>(nums.size()) - k + 1);

    // Deque stores element indices and has the following invariant:
    //     - there are at most k indices in the deque and they are in
    //       sorted order (lowest index at the front, highest at the back)
    //     - index i and j are only in the deque if nums[i] >= nums[j]
    //
    // Let the start of the window be at index i. The window is then moved
    // to position i + 1.
    //
    // The old maximum is at the front of the deque due to the invariant
    // above. It must now be removed if the index is less than the new
    // window starting position.
    //
    // The value at nums[i + 1] is now considered. Iterate from the back of
    // the deque, removing indices whilst their corresponding value in nums
    // is less than nums[i + 1]. This re-establishes the invariant. Note
    // that the removed elements will never be used in the current or any
    // future window position.
    //
    // Add index i + 1 to the back of the deque. If any indices remain
    // ahead of it in the queue then they must have a larger value as
    // otherwise they would have been removed in the step above.
    //
    // Repeat.
    //
    // It is O(1) to insert an element and each element is added and
    // removed at most O(n) times hence the complexity is O(n).
    std::deque<int> window;

    for (int i = 0; i < k; i++) {
      while (!window.empty() && nums[window.back()] < nums[i]) {
        window.pop_back();
      }
      window.push_back(i);
    }

    for (int i = k; i < static_cast<int>(nums.size()); i++) {
      results.push_back(nums[window.front()]);
      if (window.front() < i - k + 1) window.pop_front();

      while (!window.empty() && nums[window.back()] < nums[i]) {
        window.pop_back();
      }
      window.push_back(i);
    }

    results.push_back(nums[window.front()]);

    return results;
  }
};
