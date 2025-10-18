class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cur = 0, maxLen = 0;
        int startPos = 0;

        vector<int> lastOccurance(128, -1);

        for(int i = 0; i < s.size(); ++i) {
            char curChar = s[i];
            if (lastOccurance[curChar] == -1 || lastOccurance[curChar] < startPos) {
                ++cur;
                maxLen = max(maxLen, cur);
            } else {
                startPos = lastOccurance[curChar] + 1;
                cur =  i - lastOccurance[curChar];
            }

            lastOccurance[curChar] = i;
        }

        return maxLen;
    }
};
