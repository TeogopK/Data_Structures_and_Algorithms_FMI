// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns in the matrix
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Start from the top-right corner of the matrix
        int row = 0;
        int col = cols - 1;

        // Iterate until we go out of bounds of the matrix
        while (row < rows && col >= 0) {
            // If the current element is less than the target, move down to the next row
            if (matrix[row][col] < target) {
                row++;
                continue; // Continue to the next iteration
            }

            // If the current element is greater than the target, move left to the previous column
            if (matrix[row][col] > target) {
                col--;
                continue; // Continue to the next iteration
            }

            // If the current element is equal to the target, return true (target found)
            return true;
        }

        // If we exhaust the loop without finding the target, return false
        return false;
    }
};
