class Solution:
    def cleanIsland(self, grid, i, j, n, m):
        if not (0 <= i < n and 0 <= j < m):
            return

        if grid[i][j] == "0":
            return

        grid[i][j] = "0"
        self.cleanIsland(grid, i + 1, j, n, m)
        self.cleanIsland(grid, i - 1, j, n, m)
        self.cleanIsland(grid, i, j + 1, n, m)
        self.cleanIsland(grid, i, j - 1, n, m)

    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        islands = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    islands += 1
                    self.cleanIsland(grid, i, j, n, m)
        return islands
