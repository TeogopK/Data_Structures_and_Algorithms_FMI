class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int, int>> p;  // Store the numbers and their original indexes
        vector<int> counts(size, 0);  // Initialize the result counts array with zeros -> the array to return

        // Create a pair of (value, index) for each element in the array
        for (int i = 0; i < size; i++) {
            p.push_back({nums[i], i});
        }

        // Merge sort and count the smaller elements 
        mergeSortAndCount(p, counts, 0, size - 1);

        return counts;
    }

    // Merge two halves and count smaller elements for each left-side element
    // Since the merge sort is recursive, we can assume the two halves are already sorted
    void mergeAndCount(vector<pair<int, int>>& arr, vector<int>& counts, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);  // Temporary array to hold merged values
        int leftIndex = left;  // Pointer for left half
        int rightIndex = mid + 1;  // Pointer for right half
        int currentIndex = 0;  // Pointer for the merged array

        int rightCount = 0;  // Count how many elements from the right half are smaller

        // Merge the two halves while counting the smaller elements
        while (leftIndex <= mid && rightIndex <= right) {
            // If the current left element is less than or equal to the right element
            if (arr[leftIndex].first <= arr[rightIndex].first) {
                // Add the number of smaller right-side elements encountered so far
                counts[arr[leftIndex].second] += rightCount;
                temp[currentIndex++] = arr[leftIndex++];
            } else {
                // Increment rightCount since arr[rightIndex] is smaller than arr[leftIndex]
                rightCount++;
                temp[currentIndex++] = arr[rightIndex++];
            }
        }

        // Add the remaining elements from the left half, all of which will have rightCount smaller elements
        while (leftIndex <= mid) {
            counts[arr[leftIndex].second] += rightCount;
            temp[currentIndex++] = arr[leftIndex++];
        }

        // Add any remaining elements from the right half
        while (rightIndex <= right) {
            temp[currentIndex++] = arr[rightIndex++];
        }

        // Copy the merged elements back into the original array
        for (int i = 0; i < temp.size(); i++) {
            arr[left + i] = temp[i];
        }
    }

    // Recursive merge sort function that also counts smaller elements
    void mergeSortAndCount(vector<pair<int, int>>& arr, vector<int>& counts, int left, int right) {
        // Base case: If the array has one or no elements
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;  // Find the middle index
        // Recursively sort the left half and count smaller elements
        mergeSortAndCount(arr, counts, left, mid);
        // Recursively sort the right half and count smaller elements
        mergeSortAndCount(arr, counts, mid + 1, right);
        // Merge the two halves and count how many right elements are smaller than each left element
        mergeAndCount(arr, counts, left, mid, right);
    }
};
