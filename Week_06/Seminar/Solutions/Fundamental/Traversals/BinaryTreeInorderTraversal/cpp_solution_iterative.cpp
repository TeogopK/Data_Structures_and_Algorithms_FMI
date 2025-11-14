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
    void pushLeft(TreeNode* iter, stack<TreeNode*>& next) {
        while (iter) {
            next.push(iter);
            iter = iter->left;
        }
    }
public:

    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        stack<TreeNode*> next;
        pushLeft(root, next);
        auto iter = root;
        vector<int> result;
        while (!next.empty()) {
            auto current = next.top();
            result.push_back(current->val);
            next.pop();

            pushLeft(current->right, next);
        }
        return result;
    }
};