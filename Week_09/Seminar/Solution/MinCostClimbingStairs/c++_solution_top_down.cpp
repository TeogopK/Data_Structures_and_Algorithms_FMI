class Solution {
public:
    int solve(int i, vector<int>& cost, vector<int>& memo) {
        if(i <= 1) {
            return 0;
        }
        if(memo[i] != -1) { 
            return memo[i];
        }

        int oneStep = solve(i-1, cost, memo) + cost[i-1];
        int twoStep = solve(i-2, cost, memo) + cost[i-2];
        
        return memo[i] = min(oneStep, twoStep);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // -1 -> empty
        // != -1 -> already calculated
        vector<int> memo(cost.size() + 1, -1);
        return solve(cost.size(), cost, memo);
    }
};
