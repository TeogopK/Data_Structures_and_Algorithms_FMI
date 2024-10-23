class Solution {
public:
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                result = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                result = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        if(lb == -1) {
            return vector<int> {-1,-1};
        }
        int ub = upperBound(nums, target);
        return vector<int>{lb, ub};
    }
};
