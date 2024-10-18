class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            // Check if the current number is the same as the previous one
            if (nums[i] == nums[i - 1]) {
                return true; 
            }
        }

        // If no duplicates are found in the entire array
        return false; 
    }
};