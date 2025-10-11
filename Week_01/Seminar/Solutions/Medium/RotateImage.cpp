class Solution {
    void transpose(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        for(size_t row = 0; row < n; row++) {
            for(size_t col = row + 1; col < n; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
    
    void revertRows(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        for(size_t row = 0; row < n; row++) {
            for(size_t col = 0; col < n / 2; col++) {
                swap(matrix[row][col], matrix[row][n - col - 1]);
            }
            
            // alternative
            // std::reverse(matrix[row].begin(), matrix[row].end());
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        revertRows(matrix);
    }
};
