class Solution {
public:
    static bool cmp(const vector<int>& int1, const vector<int>& int2) {
        return int1[0] < int2[0];  
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<int> current = intervals[0];

        for(int i = 1; i < intervals.size(); i++) {
            if (current[1] >= intervals[i][0]) {
                current[1] = max(current[1], intervals[i][1]);
            }
            else {
                result.push_back(current);
                current = intervals[i];
            }
        }
        
        result.push_back(current);
        return result;
    }
};