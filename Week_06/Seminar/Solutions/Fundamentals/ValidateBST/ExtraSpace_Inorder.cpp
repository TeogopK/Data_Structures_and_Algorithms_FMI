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
    void dfs(TreeNode* root, vector<int>& container) {
        if(!root) {
            return;
        }
        
        dfs(root->left, container);
        container.push_back(root->val);
        dfs(root->right, container);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        dfs(root, inOrder);
        
        for(size_t i = 1; i < inOrder.size(); i++) {
            if(inOrder[i - 1] >= inOrder[i]) {
                return false;
            }
        }
        
        return true;
    }
};