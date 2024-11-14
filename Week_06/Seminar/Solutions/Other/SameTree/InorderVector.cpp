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

    const int nullptr_value = 9999999; // Outside of the Node.val constaints
public:
    void inorder(TreeNode *root, std::vector<int> &v)
    {
        if (root == nullptr)
        {
            // Without adding the nullptr, a two trees with only X value
            // will break the basic inorder solution.
            v.push_back(nullptr_value);
            return;
        }
        v.push_back(root->val);
        inorder(root->left, v);
        inorder(root->right, v);
    }

    void printVector(const std::vector<int> &v)
    {
        for (int val : v)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        std::vector<int> v1;
        std::vector<int> v2;

        inorder(p, v1);
        inorder(q, v2);

        printVector(v1);
        printVector(v2);

        return v1 == v2;
    }
};