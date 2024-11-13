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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            if(!current) {
                continue;
            }
            
            if(current->val < low) {
                q.push(current->right);
            }
            else if(current->val > high) {
                q.push(current->left);
            }
            else {
                sum += current->val;
                q.push(current->right);
                q.push(current->left);
            }
        }
        
        return sum;
    }
};