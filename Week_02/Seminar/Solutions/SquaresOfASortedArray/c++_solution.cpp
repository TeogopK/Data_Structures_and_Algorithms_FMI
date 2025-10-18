class Solution {
public:
    // O(n) time | O(n) space
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            }
            else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};
