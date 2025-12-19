struct Node{
    int x;
    int y;
    int price;
    
    bool operator<(const Node& other) const {
        return price > other.price;
    }
};
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
    bool isValid(int x, int y, int m, int n) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
    bool newPriceAddition(int directionIndex, int arrow) {
        return directionIndex != arrow - 1;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prices(m, vector<int>(n, INT_MAX));
        priority_queue<Node> nextToProcess;
        nextToProcess.push({ 0, 0, 0});
        prices[0][0] = 0;
        
        while(!nextToProcess.empty()) {
            auto current = nextToProcess.top();
            nextToProcess.pop();
            if(prices[current.x][current.y] < current.price) {
                continue;
            }
            if(current.x == m - 1 && current.y == n - 1) {
                return current.price;
            }
            
            for(int i = 0; i < 4; i++) {
                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];
                if(isValid(newX, newY, m, n)) {
                    int newPositionPrice = current.price + newPriceAddition(i, grid[current.x][current.y]);
                    if(prices[newX][newY] > newPositionPrice) {
                        prices[newX][newY] = newPositionPrice;
                        nextToProcess.push({ newX, newY, newPositionPrice});
                    }
                }
            }
        }
        
        return 0;
    }
};
