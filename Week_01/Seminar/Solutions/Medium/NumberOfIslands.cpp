class Solution {
public:
    void markIsland(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
            return;
        }
        
        if(grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0';
        markIsland(grid, i + 1, j);
        markIsland(grid, i - 1, j);
        markIsland(grid, i, j + 1);
        markIsland(grid, i, j - 1);
    }

    // O(n * m) time | O(n * m) space (stack memory!!!)
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(size_t i = 0; i < grid.size(); i++) {
            for(size_t j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    markIsland(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};
