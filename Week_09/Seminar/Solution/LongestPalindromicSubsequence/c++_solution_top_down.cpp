class Solution {
    // dp[l][r] answer for the substring from l ro r includeing lth and rth character
    int dp[1000][1000]{};

    int rec(const string& str, int l, int r) {
        if(l > r) {
            return 0;
        }
        if(l == r) {
            return 1;
        }

        if(dp[l][r] > 0) {
            return dp[l][r];
        }

        if(str[l] == str[r]) {
            return dp[l][r] = rec(str, l + 1, r - 1) + 2;
        }

        return dp[l][r] = max(rec(str, l + 1, r), rec(str, l, r - 1));
    }
public:
    int longestPalindromeSubseq(string s) {
        return rec(s, 0, s.size() - 1);
    }
};
