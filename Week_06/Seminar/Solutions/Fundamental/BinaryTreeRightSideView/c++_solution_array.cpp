class Solution {
public:
    vector<int> rightside;

    void helper(TreeNode* node, int level) {
        if (level == rightside.size()) rightside.push_back(node->val);

        if (node->right != nullptr) helper(node->right, level + 1);
        if (node->left != nullptr) helper(node->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return rightside;

        helper(root, 0);
        return rightside;
    }
};