class Solution {
public:
    // O(n) time | O(1) space
    int firstMissingPositive(vector<int>& nums) {
        for(size_t i = 0; i < nums.size(); i++) {
            // place every number at its coresponding index
            // e.g. 3 should go to index 3 - 1 = 2
            while(nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // find the first the breaks the ordering we applied
        for(size_t i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return nums.size() + 1;
    }
};
