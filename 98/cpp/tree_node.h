#pragma once

#include <optional>
#include <vector>

// LeetCode TreeNode definition.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Utility functions for TreeNode.

TreeNode *build_tree_it(
    int root,
    std::vector<std::optional<int>>::const_iterator begin,
    std::vector<std::optional<int>>::const_iterator end
) {
    auto tree = new TreeNode(root);

    if (begin == end) {
        // no values in subtrees
        return tree;
    }

    auto left_val = *begin++;
    auto right_val = *begin++;
    auto num_vals_subtree = std::distance(begin, end) / 2;

    if (left_val) {
        tree->left = build_tree_it(*left_val, begin, begin + num_vals_subtree);
    }
    if (right_val) {
        tree->right = build_tree_it(*right_val, begin + num_vals_subtree, end);
    }

    return tree;
}

TreeNode *build_tree(std::vector<std::optional<int>> &vals)
{
    return build_tree_it(*vals[0], vals.begin() + 1, vals.end());
}
