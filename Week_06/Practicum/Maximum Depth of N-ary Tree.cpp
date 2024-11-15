class Solution {
    int dfs(Node* root) {
        if (!root) {
            return 0;
        }

        int depth = 0;
        for (auto* child: root->children) {
            depth = std::max(depth, dfs(child));
        }

        return depth + 1;
    }

public:
    int maxDepth(Node* root) {
        return dfs(root);
    }
};
