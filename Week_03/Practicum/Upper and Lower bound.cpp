// Disclaimer: 
// Both std::lower_bound and std::upper_bound are designed to operate exclusively on sorted arrays (or sorted ranges). 
// Using these functions on an unsorted array will lead to undefined behavior

// std::lower_bound
// Returns an iterator to the first element that is >= the target value.
// Behavior: 
// - If the target value is found, it returns the iterator to the first occurrence of that value.
// - If the target is smaller than all elements, it points to the first element.
// - If the target is larger than the largest element, it returns the end iterator.

// std::upper_bound
// Returns an iterator to the first element that is greater than the target value.
// Behavior: 
// - If the target value is found, it returns the iterator to the first element > the target value.
// - If the target is larger than the largest element, it returns the end iterator.

// std::lower_bound and std::upper_bound return iterators.
// Here are implementations with iterators and with indexes for clarity:

vector<int>::iterator lower(vector<int>::iterator begin, vector<int>::iterator end, int target) {
    int low = 0;  // Initialize the starting index
    int high = end - begin - 1;  // Calculate the last index
    int ans = 0;  // Variable to store the index of the found target
    // Perform binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate the middle index
        if (*(begin + mid) == target) {
            ans = mid;  // Store the index if the target is found
            high = mid - 1;  // Continue searching in the left half
        }
        if (*(begin + mid) < target) {
            low = mid + 1;  // If the current value is less than target, then target should be in the right half
        } else {
            high = mid - 1;  // Move search to the left half
        }
    }
    return begin + ans;  // Return the iterator pointing to the found index
}


int upper(int target, vector<int>& nums) {
    int low = 0;  // Initialize the starting index
    int high = nums.size();  // Set the upper limit as the size of the array
    // Perform binary search
    while (low < high) {
        int mid = low + (high - low) / 2;  // Calculate the middle index
        if (nums[mid] <= target) {
            low = mid + 1;  // Move search to the right half
        } else {
            high = mid;  // Move search to the left half
        }
    }
    return high;  // Return the index of the first element greater than the target
}