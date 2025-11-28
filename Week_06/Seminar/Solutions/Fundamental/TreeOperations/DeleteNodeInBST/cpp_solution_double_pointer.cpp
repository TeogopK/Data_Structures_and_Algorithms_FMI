// stolen from https://github.com/Angeld55/Data_structures_and_algorithms_FMI/tree/main/BinarySearchTree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

TreeNode** findMinNode(TreeNode** current) {
    while ((*current)->left)
        current = &(*current)->left;
    return current;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode** current = &root;
        while (*current) {
            if (key < (*current)->val)
                current = &(*current)->left;
            else if (key > (*current)->val)
                current = &(*current)->right;
            else
                break;
        }

        if (!(*current))
            return root;

        TreeNode* toDelete = *current;
        if (!toDelete->left && !toDelete->right)
            *current = nullptr;
        else if (!toDelete->right)
            *current = toDelete->left;
        else if (!toDelete->left)
            *current = toDelete->right;
        else {
            TreeNode** rightMin = findMinNode(&toDelete->right);
            *current = *rightMin;
            *rightMin = (*rightMin)->right;
            (*current)->left = toDelete->left;
            (*current)->right = toDelete->right;
        }

        return root;
    }
};
