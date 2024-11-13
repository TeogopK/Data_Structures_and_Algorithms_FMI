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
    void _inorderTraversal(TreeNode* root, vector<int>& result) {
        if(!root) {
            return;
        }
        
        _inorderTraversal(root->left, result);
        result.push_back(root->val);
        _inorderTraversal(root->right, result);
    }
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        _inorderTraversal(root, result);
        return result;
    }
};