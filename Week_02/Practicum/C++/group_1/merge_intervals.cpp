// https://leetcode.com/problems/merge-intervals/

class Solution
{
public:
    // Comparator to sort intervals based on start time
    // If true -> el1 goes before el2
    static bool cmp(const vector<int> &el1, const vector<int> &el2)
    {
        return el1[0] < el2[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;

        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end(), cmp);

        vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            // Check for overlap
            if (current[1] >= intervals[i][0])
            {
                current[1] = max(current[1], intervals[i][1]);
            }
            // No overlap - Add current to result and update current
            else
            {
                result.push_back(current);
                current = intervals[i];
            }
        }

        result.push_back(current);

        return result;
    }
};