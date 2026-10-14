class Solution {
public:
    // complexity depends on the sorting algo behind the scenes. In c++ that is introsort
    // O(n ^ log n) time | O(log n) space
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(size_t i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]){
                return true;
            }
        }
        
        return false;
    }
};
