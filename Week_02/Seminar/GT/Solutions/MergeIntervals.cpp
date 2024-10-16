class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            if(lhs[1] == rhs[1]) {
                return lhs[0] < rhs[0];
            }
            return lhs[1] < rhs[1];
        });
        
        int result = 0;
        int end = intervals[0][1];
        for(size_t i = 1; i < intervals.size(); i++) {
            if(end > intervals[i][0]) {
                result++;
            }
            else {
                end = intervals[i][1];
            }
        }
        
        return result;
    }
};