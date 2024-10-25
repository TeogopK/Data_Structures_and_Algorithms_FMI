// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        int min = 1;
        int max = INT_MAX;
        
        // Variable to store the result
        int ans = 0;

        // Binary search
        while (min <= max) {
            // Calculate the mid to avoid overflow
            int mid = min + (max - min) / 2;

            // Check if mid is the exact square root of x
            if (mid == x / mid)
                return mid;

            // If mid is less than x / mid, it means mid is too small, so search the right half
            if (mid < x / mid) {
                min = mid + 1;
                ans = mid; // Update ans because mid is the closest smaller integer to sqrt(x)
            } 
            // If mid is greater than x / mid, it means mid is too large, so search the left half
            else {
                max = mid - 1;
            }
        }

        return ans;
    }
};
