// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

// Use a modified binary search to find the minimum element in a rotated sorted array that may contain duplicates. 
// The algorithm compares the middle element (mid) with the end element (end) to determine the search direction:
  
// - If nums[mid] > nums[end]:
//     - The minimum is in the right half.
//     - Example:
//         nums = [4, 5, 6, 7, 0, 1, 2]
//         start = 0, end = 6, mid = (0 + 6) / 2 = 3 → nums[mid] = 7
//         nums[mid] > nums[end] (7 > 2), so the minimum is in the right half.
//         Search in the range start = 4, end = 6.
  
// - If nums[mid] < nums[end]:
//     - The minimum is in the left half.
//     - Example:
//         nums = [1, 2, 3, 4, 5, 6, 7]
//         start = 0, end = 6, mid = (0 + 6) / 2 = 3 → nums[mid] = 4
//         nums[mid] < nums[end] (4 < 7), so the minimum is in the left half.
//         Continue searching in the left half: start = 0, end = 3.
  
// - In cases where duplicates exist (nums[mid] == nums[end]):
//     - The algorithm must check both halves.
//     - Example:
//         nums = [2, 2, 2, 0, 2]
//         start = 0, end = 4, mid = (0 + 4) / 2 = 2 → nums[mid] = 2
//         nums[mid] == nums[end], requiring searches on both sides.
//         - Search the left side: start = 0, end = 2 
//         - Search the right side: start = 3, end = 4 
  
// The process continues until the smallest element is identified and returned.


class Solution {
    // Helper function for binary search to find the minimum element in a rotated sorted array
    int binarySearch(vector<int>& nums, int start, int end) {
        while (true) {
            int mid = start + (end - start) / 2;  // Calculate mid-point

            // Case 1: The middle element is greater than the end element
            // This means the minimum must be in the right half, so move start to mid + 1
            if (nums[mid] > nums[end]) {
                start = mid + 1;
                continue; // Continue the search in the right half
            }

            // Case 2: The middle element is smaller than the end element
            // This means the minimum is either at mid or in the left half
            if (nums[mid] < nums[end]) {
                end = mid; // Move the end pointer to mid
                continue;  // Continue the search in the left half
            }

            // Case 3: nums[mid] == nums[end] and the search range is not exhausted (start != end)
            // This handles cases with duplicates where mid and end have the same value 
            if (nums[mid] == nums[end] && start != end) {
                // Recursively search the left half
                int leftSearchValue = binarySearch(nums, start, mid);
                if (leftSearchValue != nums[mid]) {
                    // If a different value is found in the left half, return it
                    return leftSearchValue;
                }
                // Otherwise, search the right half
                return binarySearch(nums, mid + 1, end);
            }

            // Base case: If we have reduced the range to a single element, return it as the minimum
            return nums[mid];
        }
    }

public:
    int findMin(vector<int>& nums) {
        // Initiate the binary search with the full array
        return binarySearch(nums, 0, nums.size() - 1);
    }
};
