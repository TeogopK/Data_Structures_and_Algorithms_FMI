// memoization be like.....
class Solution {
    void dfs(TreeNode* node, long targetSum, int& ans, int originalTargetSum, bool first){
        if(!node){
            return;
        }

        if(node->val == targetSum){
            ++ans;
        }

        dfs(node->left, targetSum - node->val, ans, originalTargetSum, false);
        if(first){
            dfs(node->left, originalTargetSum, ans, originalTargetSum, true);
        }

        dfs(node->right, targetSum - node->val, ans, originalTargetSum, false);
        if(first){
            dfs(node->right, originalTargetSum, ans, originalTargetSum, true);
        }
    }

public:
    int pathSum(TreeNode* root, long targetSum) {
        int ans = 0;
        dfs(root, targetSum, ans, targetSum, true);
        return ans;
    }
};

class Solution {
    int dfs(TreeNode* node, int targetSum, long prefixSum, std::map<long, int>& pathsWithPrefixSum) {
        if (!node) {
            return 0;
        }

        prefixSum += node->val;
        int paths = 0;
        if (pathsWithPrefixSum.count(prefixSum - targetSum)) {
            paths += pathsWithPrefixSum[prefixSum - targetSum];
        }

        pathsWithPrefixSum[prefixSum]++;
        paths += dfs(node->left, targetSum, prefixSum, pathsWithPrefixSum);
        paths += dfs(node->right, targetSum, prefixSum, pathsWithPrefixSum); 
        pathsWithPrefixSum[prefixSum]--;
        return paths;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        std::map<long, int> pathsWithPrefixSum;
        pathsWithPrefixSum[0] = 1;
        return dfs(root, targetSum, 0l, pathsWithPrefixSum);
    }
};
