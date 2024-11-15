class Solution {
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        return 1 + std::max(dfs(node->left), dfs(node->right));
    }

public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
