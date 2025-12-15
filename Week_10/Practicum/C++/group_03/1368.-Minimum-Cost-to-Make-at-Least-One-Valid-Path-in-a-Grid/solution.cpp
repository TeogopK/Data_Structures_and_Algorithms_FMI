struct Point {
    int x;
    int y;
    int W;

    friend bool operator<(const Point& lhs, const Point& rhs) {
        return lhs.W > rhs.W;
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector(grid[0].size(), INT_MAX));
        ans[0][0] = 0;

        vector<pair<int, int>> directions(4);
        directions[0] = {0, 1};
        directions[1] = {0, -1};
        directions[2] = {1, 0};
        directions[3] = {-1, 0};
        
        priority_queue<Point, vector<Point>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            Point curPoint = pq.top();
            if (curPoint.x == grid.size() - 1 && curPoint.y == grid[0].size() - 1) {
                return ans[curPoint.x][curPoint.y];
            }
            pq.pop();

            if (curPoint.W > ans[curPoint.x][curPoint.y]) {
                continue;
            }

            for (pair<int, int> dir : directions) {
                Point next = {curPoint.x + dir.first, curPoint.y + dir.second, -1};
                if (next.x < 0 || next.x >= grid.size() || next.y < 0 || next.y >= grid[0].size()) {
                    continue;
                }
                
                int extra = (directions[grid[curPoint.x][curPoint.y] - 1] != dir);
                if (curPoint.W + extra < ans[next.x][next.y]) {
                    ans[next.x][next.y] = curPoint.W + extra;
                    pq.push({next.x, next.y, ans[next.x][next.y]});
                }
            }
        }

        return -1;
    }
};
