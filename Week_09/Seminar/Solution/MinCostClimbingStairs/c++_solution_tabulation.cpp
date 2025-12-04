// v1
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(size_t i = 2; i < cost.size(); i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[cost.size() - 2], dp[cost.size() - 1]);
    }
};

// v2
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        for(size_t i = 2; i < dp.size(); i++) {
            auto option1 = dp[i - 2] + cost[i - 2];
            auto option2 = dp[i - 1] + cost[i - 1];
            dp[i] = min(option1, option2);
        }
        
        return dp.back();
    }
};
