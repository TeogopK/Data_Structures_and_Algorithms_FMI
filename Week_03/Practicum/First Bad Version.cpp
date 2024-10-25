// https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // We are using binary search to efficiently find the first bad version.
        // Start at version 1 and end at version n (the total number of versions).
        int start = 1;
        int end = n;

        // Continue searching as long as start is less than end
        while (start < end) {
            // Calculate the mid-point of the current range to avoid overflow
            int mid = start + (end - start) / 2;

            // If mid is not a bad version, that means the first bad version
            // is after mid, so we update start to mid + 1
            if (!isBadVersion(mid)) {
                start = mid + 1;
                continue;  // Continue with the updated range
            }

            // If mid is a bad version, it might be the first bad version,
            // so we narrow the search range by setting end to mid
            end = mid;
        }

        // At the end of the loop, start and end will point to the first bad version
        return start;
    }
};