// https://leetcode.com/problems/same-tree/

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
    const int nullptr_value = 9999999; // извън ограниченията за Node.val

    void preorder(TreeNode* root, vector<int>& v) {
        if (!root) {
            // Без да добавяме nullptr, тези две дървета ще дадат един и същ масив [1, 2]:
            //    1         1
            //     \       /
            //      2     2
            v.push_back(nullptr_value);
            return;
        }

        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1;
        vector<int> v2;

        preorder(p, v1);
        preorder(q, v2);

        return v1 == v2;
    }
};
