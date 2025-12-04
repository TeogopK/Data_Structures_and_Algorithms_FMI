class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] ще съдържа дължината на най-дългата нарастваща подпоследователност,
        // която завършва на позиция i
        vector<int> dp(nums.size());

        for (size_t i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (size_t j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};