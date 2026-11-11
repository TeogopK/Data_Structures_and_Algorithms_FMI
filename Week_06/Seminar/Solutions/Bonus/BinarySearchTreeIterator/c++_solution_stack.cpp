// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
    // Итеративният inorder, разделен на стъпки. В стека има най-много h възела,
    // а next() е O(1) амортизирано, защото всеки възел влиза и излиза от стека по веднъж.
    stack<TreeNode*> next_;

    void pushLeft(TreeNode* node) {
        while (node) {
            next_.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* current = next_.top();
        next_.pop();
        pushLeft(current->right);
        return current->val;
    }

    bool hasNext() {
        return !next_.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
