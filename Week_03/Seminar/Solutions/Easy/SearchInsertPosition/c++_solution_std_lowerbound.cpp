class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};