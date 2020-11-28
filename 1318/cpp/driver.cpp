#include <utility>
#include <tuple>
#include <iostream>
#include <vector>

#include "solution.cpp"

using std::pair;
using std::tuple;
using std::vector;

int main()
{
    Solution s;
    vector<pair<tuple<int, int, int>, int>> tests = {
        {{2, 6, 5}, 3},
        {{4, 2, 7}, 1},
        {{1, 2, 3}, 0}
    };
    for (auto test : tests) {
        auto inputs = std::get<0>(test);
        auto result = s.minFlips(
            std::get<0>(inputs),
            std::get<1>(inputs),
            std::get<2>(inputs)
        );
        if (result != std::get<1>(test)) {
            std::cout << "Test failure: "
                      << "minFlips("
                      << std::get<0>(inputs) << ", "
                      << std::get<1>(inputs) << ", "
                      << std::get<2>(inputs) << ")"
                      << " = " << result
                      << " != " << std::get<1>(test)
                      << std::endl;
            return 1;
        }
    }
    std::cout << "Tests pass!" << std::endl;
}
