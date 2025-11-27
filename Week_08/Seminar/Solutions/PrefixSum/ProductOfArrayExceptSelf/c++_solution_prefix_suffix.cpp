class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), ans(n);

        // prefix[i] = product of nums[0]..nums[i-1]
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // suffix[i] = product of nums[i+1]..nums[n-1]
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // answer = prefix * suffix
        for (int i = 0; i < n; ++i) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};