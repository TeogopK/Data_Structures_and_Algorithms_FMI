class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(100, -1);
        return robTo(nums.size() - 1, nums, memo);
    }
private:
    int robTo(int i, const vector<int>& nums, vector<int>& memo) {
        if (i < 0) {
            return 0;
        }
        if (memo[i] > -1) {
            return memo[i];
        }

        // Recursive relation evaluation to get the optimal answer.
        int ans = max(robTo(i - 1, nums, memo), robTo(i - 2, nums, memo) + nums[i]);

        // Cache for future use.
        return memo[i] = ans;
    }
};
