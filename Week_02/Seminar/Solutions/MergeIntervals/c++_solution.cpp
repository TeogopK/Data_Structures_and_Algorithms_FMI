class Solution {
public:
    // O(n * log n) time | O(1) space
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
};
