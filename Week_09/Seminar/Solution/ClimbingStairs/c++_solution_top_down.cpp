class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        
        static int dp[46]{};
        if(dp[n] == 0) {
            dp[n] = climbStairs(n - 2) + climbStairs(n - 1);
        }
        
        return dp[n];
    }
};
