// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    // O(n * log n) time | O(log n) space
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        int i = 0;
        while(i < intervals.size()) {
            vector<int> curr = intervals[i];
            i++;
            while(i < intervals.size() && curr[1] >= intervals[i][0]) {
                curr[1] = max(curr[1], intervals[i][1]);
                i++;
            }
            result.push_back(curr);
        }
        
        return result;
    }

    // v2
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
