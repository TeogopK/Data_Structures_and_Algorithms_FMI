// We can not return the result with one inorder traversal,
// because the height of right subtree is still unkown at the time of print
int dfs(TreeNode *root, const int depth, std::unordered_map<TreeNode *, int> &m)
{
    if (!root)
    {
        return 0;
    }
    int left_depth = dfs(root->left, depth + 1, m);
    int right_depth = dfs(root->right, depth + 1, m);

    int max_depth = std::max({depth, left_depth, right_depth});
    m[root] = max_depth;

    return std::max(left_depth, right_depth) + 1;
}

void print_inorder(TreeNode *root, std::unordered_map<TreeNode *, int> &m)
{
    if (!root)
    {
        return;
    }
    print_inorder(root->left, m);
    std::cout << m[root] << " ";
    print_inorder(root->right, m);
}

void main(TreeNode *root)
{
    std::unordered_map<TreeNode *, int> m;

    dfs(root, 0, m);
    print_inorder(root, m);

    return;
}