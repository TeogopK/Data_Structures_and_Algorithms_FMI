// Treat the 2D matrix as a 1D array and perform binary search on it.
class Solution {
public:
    pair<int, int> getIndexes(int i, int m, int n) {
        int row = i / n;
        int col = i % n;
        
        return make_pair(row, col);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            auto indexes = getIndexes(mid, matrix.size(), matrix[0].size());
            
            if(target == matrix[indexes.first][indexes.second]) {
                return true;
            }
            else if(target > matrix[indexes.first][indexes.second]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
                                
        return false;
    }
};