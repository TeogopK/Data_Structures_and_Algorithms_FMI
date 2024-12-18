struct Node{
    int x;
    int y;
    int removedObstacles;
    
    bool operator<(const Node& other) const {
        return removedObstacles > other.removedObstacles;
    }
};
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
    bool isValid(int x, int y, int m, int n) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
        priority_queue<Node> nextToProcess;
        nextToProcess.push({ 0, 0, 0});
        minObstacles[0][0] = 0;
        
        while(!nextToProcess.empty()) {
            auto current = nextToProcess.top();
            nextToProcess.pop();
            if(minObstacles[current.x][current.y] < current.removedObstacles) {
                continue;
            }
            // early exit
            if(current.x == m - 1 && current.y == n - 1) {
                return current.removedObstacles;
            }
            
            for(int i = 0; i < 4; i++) {
                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];
                if(isValid(newX, newY, m, n)) {
                    int newPositionRemovedObstacles = current.removedObstacles + grid[newX][newY];
                    if(minObstacles[newX][newY] > newPositionRemovedObstacles) {
                        minObstacles[newX][newY] = newPositionRemovedObstacles;
                        nextToProcess.push({ newX, newY, newPositionRemovedObstacles});
                    }
                }
            }
        }
        
        return 0;
    }
};
