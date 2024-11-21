class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        if(nums.size() == 1) {
            return nums[0];
        }

        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for(size_t i = 2; i < nums.size(); i++) {
            int temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }

        return second;
    }
};