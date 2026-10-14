class Solution {
public:
    // O(n * log n) time | O(log n) space
    vector<int> sortedSquares(vector<int>& nums) {
        for(size_t i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};
