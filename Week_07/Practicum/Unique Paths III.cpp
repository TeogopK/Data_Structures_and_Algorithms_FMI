// Backtracking is a recursive approach used to explore all possible paths or configurations by making 
// a choice, moving forward, and then undoing the choice (backtracking) to try other options. In this problem, we mark 
// cells as visited when we move to them, explore all valid directions, and then reset the cell back to its original 
// state when returning. This ensures that all potential paths are explored without revisiting the same cell in the same path.

// Time complexity - O(4^k)

class Solution {
public:
    int ans = 0;

    // (row + rowDirections[0]; col + colDirections[0]) => move up
    // (row + rowDirections[1]; col + colDirections[1]) => move right
    // (row + rowDirections[2]; col + colDirections[2]) => move down
    // (row + rowDirections[3]; col + colDirections[3]) => move left
    int rowDirections[4] = {-1, 0, 1, 0};
    int colDirections[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& grid, int row, int col, int empty) {
        if (grid[row][col] == 2) {
            if (empty == 0) {
                ans++;
            }
            return;
        }

        // Temporarily mark the current cell as visited
        int temp = grid[row][col];
        grid[row][col] = -2;

        // Explore all four directions
        for (int i = 0; i < 4; i++) {
            int nextRow = row + rowDirections[i];
            int nextCol = col + colDirections[i];

            // Check boundaries and whether the next cell is valid
            if (nextRow >= 0 && nextRow < grid.size() &&
                nextCol >= 0 && nextCol < grid[0].size() &&
                grid[nextRow][nextCol] >= 0) {  // Valid cell
                dfs(grid, nextRow, nextCol, empty - 1);
            }
        }

        // Backtrack: Reset the cell to its original state
        grid[row][col] = temp;
    }

    int uniquedfsIII(vector<vector<int>>& grid) {
        int startRow = 0, startCol = 0, empty = 0;

        // Find the starting position and count empty squares
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    startRow = row;
                    startCol = col;
                } else if (grid[row][col] == 0) {
                    empty++;
                }
            }
        }

        dfs(grid, startRow, startCol, empty + 1);  // +1 includes the starting cell
        return ans;
    }
};
