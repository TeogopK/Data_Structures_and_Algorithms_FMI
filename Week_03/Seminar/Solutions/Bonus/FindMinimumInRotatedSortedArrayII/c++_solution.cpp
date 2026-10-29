// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] < nums[right]) { // right is sorted, it is either mid or something on the left
                right = mid;
            }
            else if(nums[mid] > nums[right]) { // left to mid is sorted, the answer is between mid+1 and right
                left = mid + 1;
            }
            else { // nums[mid] == nums[right], we can't tell which half has the minimum, but right is a duplicate and can be dropped
                right--;
            }
        }

        return nums[left];
    }
};
