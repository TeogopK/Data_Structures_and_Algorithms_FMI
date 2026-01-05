struct Edge {
    int to;
    int w;

    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs.w > rhs.w;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;

        vector<vector<Edge>> edges(n + 1, vector<Edge>());
        for (auto& edge : times) {
            edges[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<Edge> pq;

        pq.push({k, 0});

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if (result[cur.to] < cur.w) {
                continue;
            }

            for(Edge& e : edges[cur.to]) {
                if (cur.w + e.w < result[e.to]) {
                    result[e.to] = cur.w + e.w;
                    pq.push({e.to, result[e.to]});
                }
            }
        }

        int resMax = INT_MIN;
        for (int i = 1; i <= n ; ++i) {
            resMax = max(resMax, result[i]);
            //cout << "at i=" << i << "the value is: "<< result[i] << endl;
        }
        return (resMax == INT_MAX) ? -1 : resMax;
    }
};
