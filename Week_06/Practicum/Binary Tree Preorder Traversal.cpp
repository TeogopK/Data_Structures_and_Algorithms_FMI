class Solution {
public:
    void dfs(TreeNode* node, vector<int>& traversal) {
        if (!node) {
            return;
        }

        traversal.push_back(node->val);
        dfs(node->left, traversal);
        dfs(node->right, traversal);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        dfs(root, traversal);
        return traversal;
    }
};
