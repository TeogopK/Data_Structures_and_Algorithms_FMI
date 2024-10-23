class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                return mid;
            }
            // everytime only one of the two parts is completely sorted
            if(nums[left] <= nums[mid]) { // left part is sorted
                if(nums[left] <= target && target < nums[mid]) { // if target is in the sorted part
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else { // nums[left] > nums[mid] => right is sorted
                if(nums[mid] < target && target <= nums[right]) { // if target is in the sorted part
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};