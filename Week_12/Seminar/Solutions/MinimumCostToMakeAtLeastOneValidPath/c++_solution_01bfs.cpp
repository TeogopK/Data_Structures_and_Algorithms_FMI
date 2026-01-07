#include <vector>
#include <deque>
#include <climits>
using namespace std;

struct Cell {
    int x;
    int y;
};

vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

class Solution {
    bool isValid(int x, int y, int m, int n) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<Cell> dq;

        dq.push_back({ 0, 0 });
        cost[0][0] = 0;

        while (!dq.empty()) {
            Cell current = dq.front();
            dq.pop_front();

            if (current.x == m - 1 && current.y == n - 1) {
                return cost[current.x][current.y];
            }

            for (int i = 0; i < 4; i++) {
                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];

                if (isValid(newX, newY, m, n)) {
                    // Cost is 0 if moving in arrow's direction, 1 otherwise
                    int edgeCost = (i == grid[current.x][current.y] - 1) ? 0 : 1;
                    int newCost = cost[current.x][current.y] + edgeCost;

                    if (newCost < cost[newX][newY]) {
                        cost[newX][newY] = newCost;

                        if (edgeCost == 0) {
                            dq.push_front({ newX, newY });
                        }
                        else {
                            dq.push_back({ newX, newY });
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
