class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumToIndex;
        sumToIndex[0] = -1;
        int result = 0;
        // Prefix sum, we will accumulate it on the fly
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1 and 1 as +1
            sum += (nums[i] == 1 ? 1 : -1);
            if (sumToIndex.find(sum) == sumToIndex.end()) {
                sumToIndex[sum] = i;
            }
            else {
                result = max(result, i - sumToIndex[sum]);
            }
        }

        return result;
    }
};