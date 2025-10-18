class Solution {
public:
    // O(n * log n) time | O(log n) space
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
            });

        int result = 0;
        int end = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); i++) {
            if (end > intervals[i][0]) {
                result++;
            }
            else {
                end = intervals[i][1];
            }
        }

        return result;
    }
};