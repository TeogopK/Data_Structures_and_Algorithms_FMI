class Solution {
public:
    // Helper function to calculate the number of unique paths
    // from the (row, col) position to the start position (0, 0).
    int move(int row, int col, vector<vector<int>>& memo) {
        // Base case: If out of bounds (negative row or column), return 0 (no paths).
        if (row < 0 || col < 0) 
            return 0;

        // Base case: If we are at the top-left corner (0, 0), return 1 (1 valid path).
        if (row == 0 && col == 0) 
            return 1;
        
        // Check if the result for the current position is already computed.
        if(memo[row][col] == -1) {
            // If not, calculate it by summing the results from the top (row-1, col) and left (row, col-1).
            memo[row][col] = move(row - 1, col, memo) + move(row, col - 1, memo);
        }

        // Return the memoized result for the current position (row, col).
        return memo[row][col];
    }

    int uniquePaths(int m, int n) {
        // Initialize a 2D memoization table with size m x n, filled with -1.
        // -1 means that the number of paths to that cell hasn't been computed yet.
        vector<vector<int>> memo(m, vector<int>(n, -1));

        // Start the recursive calculation from the bottom-right corner (m-1, n-1).
        return move(m - 1, n - 1, memo);
    }
};
