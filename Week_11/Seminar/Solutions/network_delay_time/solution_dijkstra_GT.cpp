struct Edge {
    int to;
    int weight;
};

struct Node {
    int index;
    int distance;
    bool operator<(const Node& rhs) const {
        return distance > rhs.distance;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adj list
        unordered_map<int, vector<Edge>> graph;
        for(auto& edge: times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        // dijkstra
        vector<int> distances(n + 1, INT_MAX);
        unordered_set<int> visited;
        distances[k] = 0;
        priority_queue<Node> pq;
        pq.push({k, 0});
        while(!pq.empty()) {
            auto next = pq.top();
            pq.pop();
            if(visited.count(next.index)) continue;
            visited.insert(next.index);
            
            for(auto& adj: graph[next.index]) {
                if(visited.count(adj.to)) continue;
                
                int newDistance = next.distance + adj.weight;
                if(newDistance < distances[adj.to]) {
                    distances[adj.to] = newDistance;
                    pq.push({ adj.to, newDistance });
                }
            }
        }

        // evaluate result
        int maxElement = -1;
        for(size_t i = 1; i <= n; i++) {
            maxElement = std::max(maxElement, distances[i]);
        }
        
        return maxElement == INT_MAX ? -1 : maxElement;
    }
};
