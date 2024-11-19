int dfs(TreeNode *root, const int depth = 0)
{
    if (!root)
    {
        return 0;
    }
    int left_depth = dfs(root->left, depth + 1);
    int right_depth = dfs(root->right, depth + 1);

    int max_depth = std::max({depth, left_depth, right_depth});
    std::cout << max_depth << " ";

    return std::max(left_depth, right_depth) + 1;
}