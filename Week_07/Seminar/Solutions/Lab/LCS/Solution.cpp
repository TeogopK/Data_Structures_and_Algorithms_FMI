class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // one extra row and cols for empty string
        // https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        for(size_t i = 0; i < text1.size(); i++) {
            for(size_t j = 0; j < text2.size(); j++) {
                if(text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[text1.size()][text2.size()];
    }
};