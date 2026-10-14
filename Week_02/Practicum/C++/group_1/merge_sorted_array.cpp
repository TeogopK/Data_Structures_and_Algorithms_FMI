// https://leetcode.com/problems/merge-sorted-array/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i1 = m - 1;    // Last index of nums1’s valid part
        int i2 = n - 1;    // Last index of nums2
        int i = m + n - 1; // Last index of nums1 total space

        // Merge from the back
        while (i1 >= 0 && i2 >= 0)
        {
            if (nums1[i1] > nums2[i2])
            {
                nums1[i--] = nums1[i1--];
            }
            else
            {
                nums1[i--] = nums2[i2--];
            }
        }

        // Copy remaining nums2 elements (if any)
        while (i2 >= 0)
        {
            nums1[i--] = nums2[i2--];
        }
    }
};
