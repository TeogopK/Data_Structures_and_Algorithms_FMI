class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(size_t i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};
