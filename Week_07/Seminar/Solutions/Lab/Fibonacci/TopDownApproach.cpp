class Solution {
public:
    int fib(int n) {
        if(n == 1 || n == 0) {
            return n;
        }
        
        static int dp[31]{};
        if(dp[n] == 0) {
            dp[n] = fib(n - 1) + fib(n - 2);
        }
        
        return dp[n];
    }
};