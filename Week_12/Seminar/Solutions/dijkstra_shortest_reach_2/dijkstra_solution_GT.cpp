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

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    unordered_map<int, vector<Edge>> graph;
    for(size_t i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<int> distances(n, INT_MAX);
    distances[s - 1] = 0;
    priority_queue<Node> nextToProcess;
    nextToProcess.push({s, 0});
    while(!nextToProcess.empty()) {
        auto next = nextToProcess.top();
        nextToProcess.pop();
        
        if(next.distance > distances[next.index - 1]) continue;
        
        for(auto& adj: graph[next.index]) {
            int newDistance = next.distance + adj.weight;
            if(newDistance < distances[adj.to - 1]) {
                distances[adj.to - 1] = newDistance;
                nextToProcess.push({ adj.to, newDistance });
            }
        }
    }
    distances.erase(distances.begin() + s - 1);
    for(size_t i = 0; i < distances.size(); i++) {
        if(distances[i] == INT_MAX) {
            distances[i] = -1;
        }
    }
    return distances;
}
