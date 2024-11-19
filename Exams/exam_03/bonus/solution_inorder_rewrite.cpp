// We can not return the result with one inorder traversal,
// because the height of right subtree is still unkown at the time of print
int dfs(TreeNode *root, const int depth)
{
    if (!root)
    {
        return 0;
    }
    int left_depth = dfs(root->left, depth + 1);
    int right_depth = dfs(root->right, depth + 1);

    int max_depth = std::max({depth, left_depth, right_depth});
    root->val = max_depth;

    return std::max(left_depth, right_depth) + 1;
}

void print_inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    print_inorder(root->left);
    std::cout << root->val << " ";
    print_inorder(root->right);
}

void main(TreeNode *root)
{
    dfs(root, 0);
    print_inorder(root);

    return;
}