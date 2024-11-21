class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [
            [0 for _ in range(n)] for _ in range(m)
        ]

        # Initialize empty matrix
        # [[0, 0, 0]
        # [0, 0, 0]
        # [0, 0, 0]]

        for i in range(m):
            dp[i][0] = 1

        for i in range(n):
            dp[0][i] = 1

        # [[1, 1, 1]
        # [1, 0, 0]
        # [1, 0, 0]]


        # Fill in the remaining zeros
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[-1][-1]