class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (size_t i = 0; i < text1.size(); i++) {
            for (size_t j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }

    int longestPalindromeSubseq(string text1) {
        string text2 = text1;
        reverse(text2.begin(), text2.end());

        // Това е възможно, защото палиндромната подпоследователност в text1
        // ще бъде общ подниз с обратния текст text2
        return longestCommonSubsequence(text1, text2);
    }
};
