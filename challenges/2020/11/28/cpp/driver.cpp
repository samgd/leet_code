#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "fast_solution.h"

int main()
{
    // {window size, input, expected output}
    std::vector<std::tuple<int, std::vector<int>, std::vector<int>>>  tests {
        std::make_tuple<int, std::vector<int>, std::vector<int>>(
            3, {1, 3, -1, -3, 5, 3, 6, 7}, {3, 3, 5, 5, 6, 7}
        ),
        std::make_tuple<int, std::vector<int>, std::vector<int>>(
            1, {1}, {1}
        )
    };

    Solution s;

    for (auto &test : tests) {
        auto result = s.maxSlidingWindow(std::get<1>(test), std::get<0>(test));

        if (!std::equal(
                result.begin(), result.end(),
                std::get<2>(test).begin(), std::get<2>(test).end()))
        {
            std::cout << "Test failed!" << std::endl;
            return 1;
        }
    }

    std::cout << "Tests pass!" << std::endl;
}
