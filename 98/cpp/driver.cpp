#include <iostream>
#include <optional>
#include <vector>

#include "solution.cpp"
#include "tree_node.h"

using tree_vector = std::vector<std::optional<int>>;
using test_case = std::pair<bool, tree_vector>;

int main()
{
    Solution s;

    std::vector<test_case> tests = {
        {true, {0}},
        {true, {0, -1, 1}},
        {false, {0, 1, -1}},
        {true, {2, 1, 3}},
        {false, {5, 1, 4, std::nullopt, std::nullopt, 3, 6}},
        {false, {10, 5, 15, std::nullopt, std::nullopt, 6, 20}}
    };

    for (auto test : tests) {
        auto tree = build_tree(std::get<1>(test));

        if (s.isValidBST(tree) != std::get<0>(test)) {
            std::cout << "Test failed!" << std::endl;
            return 1;
        }
    }
    std::cout << "Tests pass!" << std::endl;
}
