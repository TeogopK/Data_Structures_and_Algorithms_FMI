class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(size_t iter = 0, nextNumberIndex = 0; iter < nums.size(); iter++) {
            if(nums[iter] != 0) {
                swap(nums[nextNumberIndex], nums[iter]);
                nextNumberIndex++;
            }
        }
        
    }
};