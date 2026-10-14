class Solution {
public:
    // O(n * log n) time | O(log n) space
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};