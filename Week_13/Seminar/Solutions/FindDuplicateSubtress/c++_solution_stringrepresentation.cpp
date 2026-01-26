class Solution {
public:
    unordered_map<string, int> freq;
    vector<TreeNode*> result;

    string dfs(TreeNode* root) {
        if (!root) return "#";

        string left  = dfs(root->left);
        string right = dfs(root->right);

        // again this is some form of hashing, but heavier
        string str = "(" + left + ")" + to_string(root->val) + "(" + right + ")";

        if (++freq[str] == 2) {
            result.push_back(root);
        }

        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return result;
    }
};
