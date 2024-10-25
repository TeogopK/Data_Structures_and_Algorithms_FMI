// https://leetcode.com/problems/search-in-rotated-sorted-array/description

class Solution {
public:
    // FIRST APPROACH: Find the rotation point and then search for the target
    // This function first locates the rotation point (smallest element) using a modified binary search. 
    // After identifying the rotation, it resets the search bounds and performs a standard binary search,
    // adjusting the mid index for rotation. If the target is found, its index is returned; otherwise, -1 is returned.
    int search1(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int offset = 0;

        // Find the index of the smallest element (rotation point)
        while(true) {
            int mid = start + (end - start) / 2;  // Calculate mid index
            int current = nums[mid];  // Get the middle element

            // If mid element is greater than the end element, the minimum is in the right half
            if(current > nums[end]) {
                start = mid + 1;  // Move start to mid + 1
                continue;  // Continue searching
            }

            // If mid element is less than the end element, the minimum is in the left half
            if (current < nums[end]) {
                end = mid;  // Move end to mid
                continue;  // Continue searching
            }

            // If current equals the end, we have duplicates
            offset = mid;  // Store the rotation index
            break;  // Exit the loop
        }

        // Reset start and end for the binary search of the target
        start = 0, end = nums.size() - 1;

        // Binary search adjusted for the rotation
        while(true) {
            int mid = start + (end - start) / 2;  // Calculate mid index
            int index = (mid + offset) % nums.size();  // Adjust mid for the rotation
            int current = nums[index];  // Get the adjusted current element

            // Check if the search space is valid
            if(start > end){
                return -1;  // Target not found
            }

            // Perform standard binary search comparisons
            if(current > target) {
                end = mid - 1;  // Target is in the left half
                continue;  // Continue searching
            }

            if (current < target) {
                start = mid + 1;  // Target is in the right half
                continue;  // Continue searching
            }

            return index;  // Target found, return its index
        }
    }

    // SECOND APPROACH: Directly search while considering the rotation
    // This function searches for a target value in a rotated sorted array
    // The algorithm maintains two pointers, left and right, to define the search range.
    // In each iteration, it calculates the mid index and checks if the target is found.
    // It then determines whether the left or right half of the array is sorted.
    // Based on the sorted half, it decides where to continue the search.
    // If the target is not found, the function returns -1.
    int search2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        // Perform binary search directly on the rotated sorted array
        while (left <= right) {
            mid = left + (right - left) / 2;  // Calculate mid index 

            // Check if mid element is the target
            if (nums[mid] == target){
                return mid;  // Target found, return its index
            }

            // Check if the left side is sorted
            if (nums[left] <= nums[mid]) {
                // If target is in the left sorted half
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;  // Search in the left half
                } else {
                    left = mid + 1;  // Search in the right half
                }
            } else { // Right side is sorted
                // If target is in the right sorted half
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;  // Search in the right half
                } else {
                    right = mid - 1;  // Search in the left half
                }
            }
        }

        return -1;  // Target not found
    }
};
