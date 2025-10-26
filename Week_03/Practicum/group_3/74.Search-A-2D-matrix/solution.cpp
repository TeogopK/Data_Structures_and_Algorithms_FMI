class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = findRow(matrix, target, 0, matrix.size() - 1);
        if (r == -1) {
            return false;
        }
        int idx = lower_bound(matrix[r].begin(), matrix[r].end(), target) - matrix[r].begin();
        if (idx == matrix[r].size()) {
            return false;
        }
        cout << idx;
        return matrix[r][idx] == target;
    }

    int findRow(vector<vector<int>>& matrix, int target, int l, int r) {
        if (r < l) {
            return r;
        }
        int mid = (r-l)/2 + l;
        if (matrix[mid][0] == target) {
            return mid;
        } else if (matrix[mid][0] > target) {
            return findRow(matrix, target, l, mid - 1);
        } else {
            return findRow(matrix, target, mid + 1, r);
        }
    }
};
