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
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) {
            return { nullptr, 0 };
        }

        auto l = dfs(root->left);
        auto r = dfs(root->right);
        // explaination
        // if left depth > right depth
        //   the LCA is in the left subtree
        if (l.second > r.second) {
            return { l.first, l.second + 1 };
        }
        // if right depth > left depth
        //   the LCA is in the right subtree
        if (l.second < r.second) {
            return { r.first, r.second + 1 };
        }

        // if left depth == right depth
        //   the LCA is the current root
        return { root, l.second + 1 };
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};