class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumToCount;
        prefixSumToCount[0] = 1;

        int result = 0;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
            auto iter = prefixSumToCount.find(sum - k);
            if (iter != prefixSumToCount.end()) {
                result += (*iter).second;
            }

            prefixSumToCount[sum]++;
        }

        return result;
    }
};