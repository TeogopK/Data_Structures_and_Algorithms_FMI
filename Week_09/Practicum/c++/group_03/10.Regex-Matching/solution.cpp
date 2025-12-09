class Solution {
public:
    bool isMatch(string s, string p) {
        vector<char> pattern;
        for(int i = 0; i < p.size(); ++i) {
            if (i != p.size() - 1 && p[i + 1] == '*') {
                pattern.push_back(-p[i]);
                i++; //skip star
                continue;
            }
            pattern.push_back(p[i]);
        }

        vector<vector<bool>> dp(pattern.size() + 1, vector<bool>(s.size() + 1, false));
        dp[0][0] = true; // empty pattern with empty word
        for (int row = 1; row <= pattern.size(); ++row) {
            for(int col = 0; col <= s.size(); ++col) {
                char newPatternSymbol = pattern[row - 1];
                if (newPatternSymbol < 0) {
                    newPatternSymbol *= -1;
                    if (dp[row - 1][col] || (col != 0 && dp[row][col - 1] && (newPatternSymbol == '.' || s[col - 1] == newPatternSymbol))) {
                        dp[row][col] = true;
                    } else {
                        dp[row][col] = false;
                    }
                } else if (newPatternSymbol == '.') {
                    dp[row][col] = (col != 0 && dp[row - 1][col - 1]);
                } else {
                    dp[row][col] = (col != 0 && dp[row - 1][col - 1] && s[col - 1] == newPatternSymbol);
                }
            }
        }
        return dp[pattern.size()][s.size()];
    }
};
