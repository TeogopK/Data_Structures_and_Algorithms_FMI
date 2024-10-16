class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy = nums1;
        nums1.reserve(m + n);
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1Copy[i] < nums2[j]) {
                nums1[i + j] = nums1Copy[i]; 
                i++;
            }
            else {
                nums1[i + j] = nums2[j];
                j++;
            }
        }
        
        while(i < m) {
            nums1[i + j] = nums1Copy[i];
            i++;
        }
        while(j < n) {
            nums1[i + j] = nums2[j];
            j++;
        }
    }
};