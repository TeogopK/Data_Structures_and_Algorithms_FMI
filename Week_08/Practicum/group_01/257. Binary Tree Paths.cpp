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
class Solution
{
public:
    vector<string> result;

    string join(const vector<int> &path)
    {
        string s;
        for (int i = 0; i < path.size(); i++)
        {
            s += to_string(path[i]);
            if (i + 1 < path.size())
                s += "->";
        }
        return s;
    }

    void dfs(TreeNode *root, vector<int> &path)
    {
        path.push_back(root->val);

        if (root->left)
        {
            dfs(root->left, path);
        }
        if (root->right)
        {
            dfs(root->right, path);
        }
        if (!root->left && !root->right)
        {
            result.push_back(join(path));
        }

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        dfs(root, path);

        return result;
    }
};