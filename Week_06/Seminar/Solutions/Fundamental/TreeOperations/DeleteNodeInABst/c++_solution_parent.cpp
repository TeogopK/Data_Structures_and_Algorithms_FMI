// https://leetcode.com/problems/delete-node-in-a-bst/

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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Вместо указател към указател пазим родителя на node-а, който трием
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        while (current && current->val != key) {
            parent = current;
            current = key < current->val ? current->left : current->right;
        }

        if (!current) {
            return root;
        }

        TreeNode* replacement = nullptr;
        if (current->left && current->right) {
            // 2 деца: най-малкият node в дясното поддърво заема мястото на current
            TreeNode* minParent = current;
            TreeNode* minNode = current->right;
            while (minNode->left) {
                minParent = minNode;
                minNode = minNode->left;
            }

            // Изключваме minNode от старата му позиция
            // Той може да има само дясно дете (не може да има ляво, защото е минимален)
            if (minParent == current) {
                minParent->right = minNode->right;
            }
            else {
                minParent->left = minNode->right;
            }

            // Свързваме заместващия node с децата на изтрития node
            minNode->left = current->left;
            minNode->right = current->right;
            replacement = minNode;
        }
        else {
            // 0 или 1 дете: заместваме с детето (или с nullptr)
            replacement = current->left ? current->left : current->right;
        }

        // Пренасочваме връзката от родителя (или корена) към заместващия node
        if (!parent) {
            root = replacement;
        }
        else if (parent->left == current) {
            parent->left = replacement;
        }
        else {
            parent->right = replacement;
        }

        // not needed in leetcode
        // delete current;

        return root;
    }
};
