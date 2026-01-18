#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
    
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

std::vector<Edge> prim(int start, int n, std::unordered_map<int, std::vector<Edge>>& graph) {
    std::priority_queue<Edge> pq;
    std::unordered_set<int> visited;
    pq.push({ start, start, 0 });

    std::vector<Edge> mstEdges;

    while (!pq.empty() && visited.size() < size_t(n)) {
        auto current = pq.top();
        pq.pop();
        if (visited.count(current.to)) {
            continue;
        }

        visited.insert(current.to);
        mstEdges.push_back(current);
        for (auto& adj : graph[current.to]) {
            if(visited.count(adj.to)) {
                continue;
            }
            pq.push(adj);
        }
    }

    return mstEdges;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::unordered_map<int, std::vector<Edge>> graph;
    for (int i = 1; i <= N; ++i) {
        graph[i] = std::vector<Edge>();
    }

    for (int i = 0; i < M; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        graph[x].push_back(Edge(x, y, w));
        graph[y].push_back(Edge(y, x, w));
    }

    int start;
    std::cin >> start;

    // Start does not matter for Prim in this case (If forest...)
    std::vector<Edge> mstEdges = prim(2, N, graph);

    int mst_weight = 0;
    for (const auto& edge : mstEdges) {
        mst_weight += edge.weight;
    }
    
    std::cout << mst_weight;
    
    return 0;
    
}
