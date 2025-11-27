class Solution {
    int prefixSums[100000];
    int suffixSums[100000];
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        // Build prefix sum
        prefixSums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i];
        }
        // Build suffix sum
        suffixSums[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSums[i] = suffixSums[i + 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? 0 : prefixSums[i - 1];
            int right = (i == n - 1) ? 0 : suffixSums[i + 1];
            if (left == right) {
                return i;
            }

            // alternative and simpler            
            // if(prefixSums[i] == suffixSums[i]) {
            //     return i;
            // }
        }
        return -1;
    }
};