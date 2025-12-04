class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] ще съдържа дължината на най-дългата обща подпоследователност
        // между text1[0..i-1] и text2[0..j-1]
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (size_t i = 0; i < text1.size(); i++) {
            for (size_t j = 0; j < text2.size(); j++) {
                // Ако символите съвпадат, увеличаваме дължината на общата подпоследователност с 1
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    // Ако не съвпадат, взимаме максималната дължина от двата възможни варианта
                    // които са без текущия символ от някой от двата текста
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};