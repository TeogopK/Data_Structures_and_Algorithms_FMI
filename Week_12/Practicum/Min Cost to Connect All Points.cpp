class Solution {
    int minDist[1000] {}; // min distance to the spanning tree

    int dist(const std::vector<int> &x, const std::vector<int> &y) {
        return std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            minDist[i] = dist(points[i], points[0]);
        }
        minDist[0] = INT_MAX;

        int minCost = 0;
        for (int i = 1; i < n; ++i) {
            int minIdx = std::min_element(minDist, minDist + n) - minDist;
            minCost += minDist[minIdx];
            minDist[minIdx] = INT_MAX;
            
            for (int i = 0; i < n; ++i) {
                if (minDist[i] < INT_MAX) {
                    minDist[i] = std::min(minDist[i], dist(points[i], 
points[minIdx]));
                }
            }
        }

        return minCost;
    }
};
