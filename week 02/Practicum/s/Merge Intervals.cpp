class Solution {
public:
    // Custom comparison function to sort intervals by their start time (first element)
    static bool cmp(const vector<int>& int1, const vector<int>& int2) {
        return int1[0] < int2[0];  
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result; // To store the merged intervals

        // Sort the intervals based on their start time using the custom comparator
        sort(intervals.begin(), intervals.end(), cmp);
        
        // Initialize the current interval as the first interval in the sorted list
        vector<int> current = intervals[0];

        for(int i = 1; i < intervals.size(); i++) {
            // Check if the current interval overlaps with the next interval
            if (current[1] >= intervals[i][0]) {
                // If they overlap, merge the intervals
                current[1] = max(current[1], intervals[i][1]);
            }
            else {
                // If they don't overlap, add the current interval to the result
                result.push_back(current);
                // Update the current interval to the next interval
                current = intervals[i];
            }
        }
        // Add the last merged interval to the result
        result.push_back(current);
        return result;
    }
};