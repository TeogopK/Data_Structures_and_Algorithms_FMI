class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            // check the indexes
            // - correct order is first occurence should be on even index
            // - second on odd
            // - if that is not correct - somewhere on the left side there is alone element
            if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                if(mid & 1) { // correct placement
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else if(mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                if(!(mid & 1)) { // correct placement
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                return nums[mid];
            }
        }
        
        return 0;
    }
};