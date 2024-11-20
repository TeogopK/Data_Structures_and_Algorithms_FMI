class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;

        deque<TreeNode *> q;
        q.push_back(root);

        bool addLeftToRight = 1;
        while (!q.empty())
        {
            int levelLength = q.size();
            vector<int> vec;
            for (int i = 0; i < levelLength; i++)
            {
                if (addLeftToRight)
                {
                    // Poping from the back, adding left to right to the front
                    if (q.back()->left)
                    {
                        q.push_front(q.back()->left);
                    }
                    if (q.back()->right)
                    {
                        q.push_front(q.back()->right);
                    }
                    vec.push_back(q.back()->val);
                    q.pop_back();
                }
                else
                {
                    // Poping from the front, adding right to left to the back
                    if (q.front()->right)
                    {
                        q.push_back(q.front()->right);
                    }
                    if (q.front()->left)
                    {
                        q.push_back(q.front()->left);
                    }
                    vec.push_back(q.front()->val);
                    q.pop_front();
                }
            }
            addLeftToRight = !addLeftToRight;
            ans.push_back(vec);
        }

        return ans;
    }
};