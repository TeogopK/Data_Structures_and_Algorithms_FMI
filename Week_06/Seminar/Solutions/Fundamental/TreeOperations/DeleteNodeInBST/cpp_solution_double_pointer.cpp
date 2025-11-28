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

 // Намира указател към указателя на минималния node в дадено поддърво
 // Използваме double pointer за да можем да модифицираме директно връзката от родителя
TreeNode** findMinNode(TreeNode** current) {
    // Най-малкият елемент в BST е винаги най-вляво
    while ((*current)->left)
        current = &(*current)->left;
    return current; // Връща указател към указателя на min node
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Използваме double pointer за да можем да модифицираме директно указателя на родителя към неговото дете
        // Вместо да пазим родителя отделно, current е указател към указателя (root или parent->left/right)
        TreeNode** current = &root;

        while (*current) {
            if (key < (*current)->val)
                current = &(*current)->left;
            else if (key > (*current)->val)
                current = &(*current)->right;
            else
                break; // Намерили сме node-а
        }

        if (!(*current))
            return root;

        // на този етап current e указател към right или left указателя на родителя на node-а, който ще трием
        // toDelete сочи към node-а който ще изтрием
        TreeNode* toDelete = *current;
        if (!toDelete->left && !toDelete->right)
            *current = nullptr;
        else if (!toDelete->right)
            *current = toDelete->left;
        else if (!toDelete->left)
            *current = toDelete->right;
        else {
            // Намираме най-малкия node в дясното поддърво
            TreeNode** rightMin = findMinNode(&toDelete->right);

            // Пренасочваме поинтъра на родителя към този минимален node
            *current = *rightMin;

            // Изключваме минималния node от старата му позиция
            // Той може да има само дясно дете (не може да има ляво, защото е минимален)
            *rightMin = (*rightMin)->right;

            // Свързваме заместващия node с децата на изтрития node
            (*current)->left = toDelete->left;   // Запазваме лявото поддърво
            (*current)->right = toDelete->right; // Запазваме дясното поддърво
        }
        // not needed in leetcode
        // delete toDelete;

        return root;
    }
};
