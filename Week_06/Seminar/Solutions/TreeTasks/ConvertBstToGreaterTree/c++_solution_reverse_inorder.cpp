// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
class Solution {
    int sum = 0;

public:
    // Обратен inorder (дясно-корен-ляво) посещава стойностите в намаляващ ред.
    // Така sum винаги е сумата на всички по-големи стойности.
    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);

        return root;
    }
};
