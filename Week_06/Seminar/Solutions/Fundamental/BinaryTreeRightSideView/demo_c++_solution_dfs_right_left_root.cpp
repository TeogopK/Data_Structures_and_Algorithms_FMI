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
    int maxDepth = 0;
public:
    void dfs(TreeNode* root, vector<int>& result, size_t depth = 0) {
        if (!root) {
            return;
        }

        dfs(root->right, result, depth + 1);
        dfs(root->left, result, depth + 1);
        if (result[depth] == -200000) {
            result[depth] = root->val;
        }
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> result(200, -200000);
        dfs(root, result);
        result.resize(maxDepth + 1);
        return result;;
    }
};