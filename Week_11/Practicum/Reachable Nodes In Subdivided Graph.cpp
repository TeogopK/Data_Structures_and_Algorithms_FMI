class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> dist(n, INT32_MAX);
        vector<vector<int>> done(n, vector<int>(n, 0));

        int reached = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) 
                continue;

            reached++; // Count the reachable original node

            for (const auto& [neighbor, w] : graph[node]) {
                // Calculate how many subdivided nodes can be traversed on this edge
                int remainingMoves = maxMoves - d;
                if (remainingMoves <= 0) 
                    continue; // No moves left to traverse this edge

                int used = min(w, remainingMoves);
                done[node][neighbor] = max(done[node][neighbor], used);

                // Distance to reach the neighbor node
                int dn = d + w + 1;
                if (dn < dist[neighbor] && dn <= maxMoves) {
                    dist[neighbor] = dn;
                    pq.push({dn, neighbor});
                }
            }            
        }  

        // Count the reachable subdivided nodes on each edge
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            reached += min(w, done[u][v] + done[v][u]);
        }

        return reached;
    }
};
