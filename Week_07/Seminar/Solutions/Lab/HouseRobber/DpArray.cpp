class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> maxDP(nums.size(), 0);
        
        maxDP[0] = nums[0];
        maxDP[1] = max(nums[0], nums[1]);
        
        for(size_t i = 2; i < nums.size(); i++) {
            maxDP[i] = max(maxDP[i - 1], nums[i] + maxDP[i - 2]);
        }
        
        return maxDP[maxDP.size() - 1];
    }
};