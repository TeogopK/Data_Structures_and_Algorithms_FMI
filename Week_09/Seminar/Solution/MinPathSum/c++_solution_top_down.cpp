class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // dp[i][j]: min path sum to (i,j); initialize to -1 (unvisited)
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minPath(grid, dp, m - 1, n - 1);
    }

private:
    int minPath(const vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        if (i < 0 || j < 0) return INT_MAX;              // Out of bounds
        if (i == 0 && j == 0) return grid[0][0];         // Start cell
        if (dp[i][j] != -1) return dp[i][j];             // Memoized
        
        int left = minPath(grid, dp, i, j - 1);
        int up = minPath(grid, dp, i - 1, j);
        dp[i][j] = grid[i][j] + min(left, up);
        return dp[i][j];
    }
};
