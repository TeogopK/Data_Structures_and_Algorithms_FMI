struct Point {
    int x;
    int y;
    int dist;
    int broke;

    friend bool operator<(const Point& l, const Point& r) {
        return l.dist > r.dist;
    }
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<Point> queue;

        int brokeFirst = grid[0][0];
        queue.push({0, 0, 0, brokeFirst});
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<pair<int, int>>> ans(grid.size(), vector<pair<int, int>>(grid[0].size(), {INT_MAX, INT_MAX}));
        ans[0][0] = {0, brokeFirst};

        while (!queue.empty()) {
            Point cur = queue.front();
            queue.pop();
            if (cur.x == grid.size() - 1 && cur.y == grid[0].size() - 1) {
                return cur.dist;
            }
            if (cur.broke > ans[cur.x][cur.y].second && cur.dist >= ans[cur.x][cur.y].first) {
                continue;
            }

            for(auto& dir : dirs) {
                Point next = {cur.x + dir.first, cur.y + dir.second};
                if (next.x < 0 || next.x >= grid.size() || next.y < 0 || next.y >= grid[0].size()) {
                    continue;
                }
                next.broke = cur.broke + grid[next.x][next.y];
                next.dist = cur.dist + 1;
                if (next.broke > k) {
                    continue;
                }
                if (next.broke >= ans[next.x][next.y].second && next.dist >= ans[next.x][next.y].first) {
                    continue;
                }
                ans[next.x][next.y] = {next.dist, next.broke};
                queue.push(next);
            }
        }
        return -1;

    }
};
