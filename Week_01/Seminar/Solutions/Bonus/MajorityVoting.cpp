class Solution {
public:
    // Boyer-Moore Majority Voting Algorithm
    // O(n) time | O(1) space
    int majorityElement(vector<int>& nums) {
        int votesForCurrent = 1;
        int current = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(votesForCurrent == 0) {
                votesForCurrent = 1;
                current = nums[i];
            }
            else if(nums[i] == current) {
                votesForCurrent++;
            }
            else {
                votesForCurrent--;
            }
        }
        
        return current;
    }
};
