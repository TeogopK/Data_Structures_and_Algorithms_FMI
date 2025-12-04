class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) {
            return n;
        }
        vector<int> dp(46, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(size_t i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
