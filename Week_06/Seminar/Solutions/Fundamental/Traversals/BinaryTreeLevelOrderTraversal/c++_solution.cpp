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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> level;
        level.push(root);
        vector<vector<int>> result;
        while (!level.empty()) {
            vector<int> currentLevel;
            size_t levelSize = level.size();
            for (size_t i = 0; i < levelSize; i++) {
                auto current = level.front();
                level.pop();
                currentLevel.push_back(current->val);
                if (current->left) {
                    level.push(current->left);
                }
                if (current->right) {
                    level.push(current->right);
                }
            }
            result.push_back(currentLevel);
        }

        return result;
    }
};