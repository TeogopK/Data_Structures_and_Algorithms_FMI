// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Find the first occurrence of the target using lower_bound
        // lower_bound returns the iterator to the first element >= target
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // If the target is not found in the array, return {-1, -1}
        // Either we reached the end of the array, or the element at "low" is not the target
        if (low == nums.size() || nums[low] != target) {
            return {-1, -1};
        }

        // Find the last occurrence of the target using upper_bound
        // upper_bound returns the iterator to the first element > target
        // Subtracting 1 gives us the last index of the target
        int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        // Return the starting and ending index of the target in the array
        return {low, up};
    }
};
