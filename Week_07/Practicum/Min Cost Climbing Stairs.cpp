// Climbing from the Bottom Up
class Solution {
public:
    int climb(int n, vector<int>& cost, vector<int>& memo) {
        // Base case: if 'n' is within the last two steps, return its cost
        if (n >= cost.size() - 2) {
            return cost[n];
        }

        // If the result for 'n' is not memoized, calculate it
        if (!memo[n]) {
            // The cost to climb from step 'n' is the current step's cost
            // plus the minimum cost of climbing from the next step or skipping one
            memo[n] = cost[n] + min(climb(n + 1, cost, memo), climb(n + 2, cost, memo));
        }

        // Return the memoized result
        return memo[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size() + 1, 0);

        // The final result is the minimum cost starting from step 0 or step 1
        return min(climb(0, cost, memo), climb(1, cost, memo));
    }
};

// Climbing from the Top Down
class Solution {
public:
    int climb(int n, vector<int>& cost, map<int, int>& memo) {
        // Base case: if 'n' is step 0 or 1, return its cost
        if (n <= 1) {
            return cost[n];
        }

        // If the result for 'n' is not memoized, calculate it
        if (memo.find(n) == memo.end()) {
            // The cost to reach step 'n' is the current step's cost
            // plus the minimum cost to climb to step 'n' from either the previous step or the step before that
            memo[n] = cost[n] + min(climb(n - 1, cost, memo), climb(n - 2, cost, memo));
        }

        // Return the memoized result
        return memo[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // Memoization map to store intermediate results (can be a vector)
        map<int, int> memo;

        // The final result is the minimum cost of reaching the top from either of the last two steps
        return min(climb(cost.size() - 1, cost, memo), climb(cost.size() - 2, cost, memo));
    }
};
