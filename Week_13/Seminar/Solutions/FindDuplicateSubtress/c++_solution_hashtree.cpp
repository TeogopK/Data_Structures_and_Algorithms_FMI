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
    int toHash(const string& str) {
        size_t hash = 0;
        for (char c : str) {
            hash = (size_t)c + (size_t)(hash << 3) + (size_t)(hash << 5) - hash;
        }
        return hash;
    }

    size_t merkle(
        TreeNode* current,
        unordered_map<size_t, size_t>& merkleHashCounter,
        unordered_set<TreeNode*>& result
    ) {
        if (!current) {
            return '$';
        }

        size_t leftMerkle  = merkle(current->left, merkleHashCounter, result);
        size_t rightMerkle = merkle(current->right, merkleHashCounter, result);

        string combined =
            to_string(leftMerkle) +
            to_string(current->val) +
            to_string(rightMerkle);

        size_t merkleValue = toHash(combined);

        if (merkleHashCounter[merkleValue] == 1) {
            result.insert(current);
        }

        merkleHashCounter[merkleValue]++;
        return merkleValue;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<size_t, size_t> merkleHashCounter;
        unordered_set<TreeNode*> result;

        merkle(root, merkleHashCounter, result);

        return vector<TreeNode*>(result.begin(), result.end());
    }
};
