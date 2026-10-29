// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] <= nums[right]) { // right is sorted, it is either mid or something on the left
                right = mid;
            }
            else { // left to mid is sorted, the answer is either mid + 1 or something between mid+1 and right
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};
