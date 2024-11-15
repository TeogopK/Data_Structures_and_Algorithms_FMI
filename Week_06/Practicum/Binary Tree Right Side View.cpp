class Solution {
    void dfs(TreeNode* node, int depth, vector<int>& view) {
        if (!node) {
            return;
        }

        if (view.size() == depth) {
            view.push_back(node->val);
        }

        dfs(node->right, depth + 1, view);
        dfs(node->left, depth + 1, view);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        dfs(root, 0, view);
        return view;
    }
};
