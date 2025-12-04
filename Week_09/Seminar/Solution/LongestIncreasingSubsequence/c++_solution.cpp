class Solution {
public:
    // Примерна таблица за nums = [10,9,2,5,3,7,101,1]
    // Индекси:    0  1 2 3 4 5 6   7
    // nums:      10  9 2 5 3 7 101 1
    // dp:         1  1 1 2 2 3 4   1

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