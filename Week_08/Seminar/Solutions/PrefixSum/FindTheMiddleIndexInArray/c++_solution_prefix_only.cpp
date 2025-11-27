class Solution {
    int prefixSums[100000];
public:
    int findMiddleIndex(vector<int>& nums) {
        prefixSums[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i];
        }

        if (prefixSums[nums.size() - 1] - nums[0] == 0) {
            return 0;
        }

        for (size_t i = 1; i < nums.size(); i++) {
            if (prefixSums[i - 1] == prefixSums[nums.size() - 1] - prefixSums[i]) {
                return i;
            }
        }

        return -1;
    }
};