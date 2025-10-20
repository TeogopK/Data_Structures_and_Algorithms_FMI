class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins(timePoints.size(), 0);
        long size = timePoints.size();
        for(int i =0; i < size; ++i) {
            mins[i] = convertStrTimeToMins(timePoints[i]);
        }
        sort(mins.begin(), mins.end());

        int minDif = INT_MAX;
        for(int i = 0; i < size - 1; ++i) {
            int curDif = abs(mins[i] - mins[i + 1]);
            minDif = min(minDif, curDif);
        }
        int lastDif = abs(mins[size - 1] - 24 * 60 - mins[0]);
        minDif = min(minDif, lastDif);
        return minDif;
    }

    int convertStrTimeToMins(string& str) {
        int h = digitFromCharToInt(str[0]) * 10 + digitFromCharToInt(str[1]);
        int m =  digitFromCharToInt(str[3]) * 10 + digitFromCharToInt(str[4]);
        return h * 60 + m;
    }

    int digitFromCharToInt(char c) {
        return c - '0';
    }
};
