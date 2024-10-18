class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize pointers for the last elements of nums1 and nums2
        int end1 = m - 1;
        int end2 = n - 1;
        // Pointer for the last position in nums1
        int curr = m + n - 1;
        
        // Merge nums1 and nums2 from the end to the beginning
        while (end1 >= 0 && end2 >= 0) {
            // Place the larger element at the current position in nums1
            if (nums1[end1] > nums2[end2] ) {
                nums1[curr--] = nums1[end1--];
            } 
            else {
                nums1[curr--] = nums2[end2--];
            }   
        }

        // If there are remaining elements in nums2, move them to the front
        while (end2 >= 0) {
            nums1[curr--] = nums2[end2--];
        }
    }
};
