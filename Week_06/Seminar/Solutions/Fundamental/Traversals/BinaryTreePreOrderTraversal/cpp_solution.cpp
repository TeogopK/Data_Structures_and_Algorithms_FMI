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
    void _preorderTraversal(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }

        result.push_back(root->val);
        _preorderTraversal(root->left, result);
        _preorderTraversal(root->right, result);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        _preorderTraversal(root, result);
        return result;
    }
};