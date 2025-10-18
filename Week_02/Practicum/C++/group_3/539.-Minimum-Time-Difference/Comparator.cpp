bool comp(string& lhs, string& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end(), comp);

        int minRes = INT_MAX;
        vector<int> mins(timePoints.size(), 0);
        for(int i = 0; i < timePoints.size(); ++i) {
            mins[i] = fromTimeStrToInt(timePoints[i]);
        }

        for(int i =0 ; i < mins.size() - 1; ++i) {
            int curTimeDiff = mins[i + 1] - mins[i];
            minRes = min(minRes, curTimeDiff);
        }

        int lastTime = mins[mins.size() - 1] - 24 * 60;
        int curTimeDiff = mins[0] - lastTime;
        minRes = min(minRes, curTimeDiff);
    
        return minRes;

    }

    int fromTimeStrToInt(const string& str) {
        int h = digitFromCharToInt(str[0]) * 10 + digitFromCharToInt(str[1]);
        int m = digitFromCharToInt(str[3]) * 10 + digitFromCharToInt(str[4]);
        return h * 60 + m;
    }

    int digitFromCharToInt(char c) {
        return c - '0';
    }
};
