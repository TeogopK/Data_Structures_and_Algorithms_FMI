// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 1 2 3 4 5 6 7 8 9 10 ... n
        // T T T T T T f f f f f f f f f f
        // 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
        int left = 0;
        int right = n;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                index = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return index;
    }
};