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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> current_level;

        if (!root)
        {
            return result;
        }

        std::queue<TreeNode *> q;
        q.push(root);

        TreeNode *current;
        int row = 1;

        while (!q.empty())
        {
            int levelSize = q.size();

            while (levelSize--)
            {
                current = q.front();
                q.pop();

                current_level.push_back(current->val);

                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
            }

            if (row++ % 2 == 0)
            {
                std::reverse(current_level.begin(), current_level.end());
            }
            result.push_back(current_level);
            current_level.clear();
        }
        return result;
    }
};