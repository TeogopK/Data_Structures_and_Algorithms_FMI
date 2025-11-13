/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validate(TreeNode* node, long long min, long long max) {
        if (!node) {
            return true;
        }

        if (min >= node->val || max <= node->val) {
            return false;
        }

        // All nodes in the left sub-tree should be less than node->val
        // All nodes in the right sub-tree should be greater than node->val
        return validate(node->left, min, node->val) && validate(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};