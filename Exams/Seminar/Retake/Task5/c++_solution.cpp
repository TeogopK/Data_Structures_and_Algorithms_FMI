class Solution {
    unordered_map<TreeNode*, TreeNode*> parent; // parent map

    void populate(TreeNode* curr) {
        if(!curr) {
            return;
        }

        if(curr->left) {
            parent[curr->left] = curr;
            populate(curr->left);
        }

        if(curr->right) {
            parent[curr->right] = curr;
            populate(curr->right);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        populate(root); // populate parent map

        // path from p to root
        unordered_set<TreeNode*> pPath;
        auto iter = p;
        while(iter) {
            pPath.insert(iter);
            iter = parent[iter];
        }

        // find where the path from q to root matches
        iter = q;
        while(iter) {
            if(pPath.count(iter)) {
                return iter;
            }
            iter = parent[iter];
        }
        
        return root;
    }
};