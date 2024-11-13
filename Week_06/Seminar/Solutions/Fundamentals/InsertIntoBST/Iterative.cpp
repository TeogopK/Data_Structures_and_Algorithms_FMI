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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }
        
        TreeNode* prev = nullptr;
        TreeNode* iter = root;
        while(iter) {
            prev = iter;
            if(iter->val > val) {
                iter = iter->left;
            }
            else {
                iter = iter->right;
            }
        }
        
        if(prev->val > val) {
            prev->left = new TreeNode(val);
        }
        else {
            prev->right = new TreeNode(val);
        }
        
        return root;
    }
};