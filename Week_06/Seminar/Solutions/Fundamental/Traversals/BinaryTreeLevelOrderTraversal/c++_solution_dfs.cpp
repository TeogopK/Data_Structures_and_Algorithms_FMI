// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    // DFS вместо BFS: подаваме дълбочината и добавяме всеки възел в result[depth].
    // Тъй като лявото дете се обхожда преди дясното, редът във всяко ниво е отляво надясно.
    void dfs(TreeNode* root, size_t depth, vector<vector<int>>& result) {
        if (!root) {
            return;
        }

        if (depth == result.size()) {
            result.push_back({});
        }
        result[depth].push_back(root->val);

        dfs(root->left, depth + 1, result);
        dfs(root->right, depth + 1, result);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
};
