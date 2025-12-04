class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp if position can be reached
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (size_t i = 0; i < nums.size(); i++) {
            if (!dp[i]) { // this position can't be reached
                return false;
            }
            int furthestJump = min(i + nums[i], nums.size() - 1);
            // mark all possible jumps
            for (int j = furthestJump; j >= i; j--) {
                // if j is marked => j-1 is marked => linear solution, we mark each dp only once
                if (dp[j]) {
                    break;
                }
                dp[j] = true;
            }
        }

        return dp[nums.size() - 1];
    }
};