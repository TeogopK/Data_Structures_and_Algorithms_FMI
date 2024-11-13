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
    void inorderReversed(TreeNode* root, int& sum) {
        if(!root) {
            return;
        }
        
        inorderReversed(root->right, sum);
        sum += root->val;
        root->val = sum;
        inorderReversed(root->left, sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inorderReversed(root, sum);
        return root;
    }
};