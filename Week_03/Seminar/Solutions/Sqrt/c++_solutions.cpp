// without result variable
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        // binary on the answer
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid <= x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left - 1;
    }
};

// with additional result variable
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int result = x;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid > x) {
                right = mid - 1;
            }
            else {
                result = mid;
                left = mid + 1;
            }
        }

        return result;
    }
};