// solution with DFS
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

// solution with BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::vector<int> view;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while (queue.size()) {
            int levelSize = queue.size();
            view.push_back(queue.front()->val);
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = queue.front();
                if (node->right) {
                    queue.push(node->right);
                }
                if (node->left) {
                    queue.push(node->left);
                }
                queue.pop();
            }
        }

        return view;
    }
};
