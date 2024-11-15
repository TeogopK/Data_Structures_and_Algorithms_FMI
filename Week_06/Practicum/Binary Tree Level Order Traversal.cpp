class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> levelOrder;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (q.size()) {
            std::vector<int> level(q.size());
            for (int i = 0; i < level.size(); ++i) {
                TreeNode* node = q.front(); q.pop();
                level[i] = node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            levelOrder.push_back(level);
        }

        return levelOrder;
    }
};
