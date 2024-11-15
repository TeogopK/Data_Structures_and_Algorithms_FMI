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

 // memoization be like.....
class Solution {
    void dfs(TreeNode* node, long targetSum, int& ans, int originalTargetSum, bool first){
        if(!node){
            return;
        }

        if(node->val == targetSum){
            ++ans;
        }

        dfs(node->left, targetSum - node->val, ans, originalTargetSum, false);
        if(first){
            dfs(node->left, originalTargetSum, ans, originalTargetSum, true);
        }

        dfs(node->right, targetSum - node->val, ans, originalTargetSum, false);
        if(first){
            dfs(node->right, originalTargetSum, ans, originalTargetSum, true);
        }
    }

public:
    int pathSum(TreeNode* root, long targetSum) {
        int ans = 0;
        dfs(root, targetSum, ans, targetSum, true);
        return ans;
    }
};