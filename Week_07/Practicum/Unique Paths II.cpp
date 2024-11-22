class Solution {
public:
    int move(int row, int col, vector<vector<int>>& memo, vector<vector<int>>& obstacleGrid) {
        // Base case: If out of bounds or there's an obstacle, return 0
        if (row < 0 || col < 0 || obstacleGrid[row][col] == 1) {
            return 0;
        }
        
        // Base case: If we're at the top-left corner, return 1
        if (row == 0 && col == 0) {
            return 1;
        }

        // Calculate the number of paths by moving from the cell above or to the left
        if (memo[row][col] == -1) {
            memo[row][col] = move(row - 1, col, memo, obstacleGrid) + move(row, col - 1, memo, obstacleGrid);
        }
        
        return memo[row][col];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Initialize the memo table with -1 (indicating that no cell has been calculated yet)
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        // Start the recursive calculation from the bottom-right corner
        return move(m - 1, n - 1, memo, obstacleGrid);
    }
};

// iterative bottom up
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();

        int paths[100][100] {};
        paths[0][0] = 1;

        int col = 1;
        while (col < n && grid[0][col] == 0) {
            paths[0][col++] = 1;
        }

        int row = 1;
        while (row < m && grid[row][0] == 0) {
            paths[row++][0] = 1;
        }

        for (row = 1; row < m; row++) {
            for (col = 1; col < n; col++) {
                if (grid[row][col] == 0) {
                    paths[row][col] = paths[row][col - 1] + paths[row - 1][col];
                }
            }
        }
        
        return paths[m - 1][n - 1];
    }
};
