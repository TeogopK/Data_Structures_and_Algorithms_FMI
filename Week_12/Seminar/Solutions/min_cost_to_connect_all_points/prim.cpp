struct Edge {
    int from;
    int to;
    int length;

    bool operator<(const Edge& other) const {
        return length > other.length;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int result = 0;
        unordered_set<int> visitedIndeces;
        priority_queue<Edge> pq;
        if(points.size() >= 2) {
            pq.push({0, 0, 0});
        }

        int visitedCount = 0;
        while(!pq.empty() && visitedCount < points.size()) {
            auto current = pq.top();
            pq.pop();
            if(visitedIndeces.count(current.to)) {
                continue;
            }
            visitedIndeces.insert(current.to);
            result += current.length;
            visitedCount++;
            for(int i = 0; i < points.size(); i++) {
                if(!visitedIndeces.count(i)) {
                    int l = abs(points[i][0] - points[current.to][0]);
                    l += abs(points[i][1] - points[current.to][1]);
                    pq.push({current.to, i, l });
                }
            }
        }

        return result;
    }
};
