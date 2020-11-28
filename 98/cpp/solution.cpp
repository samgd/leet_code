#include <optional>

#include "tree_node.h"


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::optional<int> prev_val;
        return isValidBST(root, prev_val);
    }

private:
    // Performs an in-order tree traversal, checking that the values are
    // monotonically increasing.
    bool isValidBST(TreeNode *root, std::optional<int> &prev_val)
    {
        if (!root) {
            // Base case: trivially true (no val).
            return true;
        }

        bool valid = isValidBST(root->left, prev_val);
        if (!valid) {
            // left subtree isn't valid
            return false;
        }

        if (prev_val && *prev_val >= root->val) {
            // value in left subtree is greater than root node value
            return false;
        }

        prev_val = root->val;
        return isValidBST(root->right, prev_val);
    }
};
