class Solution:
    def climbStairs(self, n: int) -> int:
        # In the array we will keep the number of times we can climb a given stair
        # the first and second can be climbed once.
        dp = [1, 1]
        
        for i in range(2, n + 1):
            # Stair i, can be climbed the number of times you can climb stair (i - 1) + stair (i - 2) 
            dp.append(dp[i - 1] + dp[i - 2])

        return dp[n]