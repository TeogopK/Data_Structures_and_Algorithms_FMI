class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        size_t allPairs = nums.size() * (nums.size() - 1) / 2;
        size_t goodPairs = 0;
        // key - (nums[x] - x) value
        // value - counter of that value
        unordered_map<int, size_t> tracker;

        for (size_t i = 0; i < nums.size(); i++) {
            int target = nums[i] - i;
            goodPairs += tracker[target];
            tracker[target]++;
        }

        return allPairs - goodPairs;
    }
};