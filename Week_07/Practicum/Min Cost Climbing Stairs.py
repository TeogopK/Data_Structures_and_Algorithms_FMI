class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [cost[0], cost[1]]

        for i in range(2, len(cost)):
            dp.append(min(dp[i - 1], dp[i - 2]) + cost[i])

        return min(dp[len(cost) - 1], dp[len(cost) - 2])