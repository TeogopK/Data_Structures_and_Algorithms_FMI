class Solution {
public:
    // Don't forget the ref
    int climb(int n, vector<int>& memo) {
        // Base cases: There is only 1 way to climb 0 or 1 step
        if (n == 0 || n == 1) {
            return 1;
        }

        if(memo[n]){
            return memo[n];
        }

        // The number of ways to climb 'n' steps is the sum of:
        // 1. The ways to climb 'n - 1' steps (taking 1 step)
        // 2. The ways to climb 'n - 2' steps (taking 2 steps)
        memo[n] = climb(n - 1, memo) + climb(n - 2, memo);
        return memo[n];
    }

    // The same as fibonaci
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0);
        return climb(n, memo);
    }
};

// bottom-up solution
class Solution {
public:
    int climbStairs(int n) {
        int steps[46] {};
        steps[1] = 1;
        steps[2] = 2;

        for (int i = 3; i <= n; ++i) {
            steps[i] = steps[i - 1] + steps[i - 2];
        }

        return steps[n];
    }
};
