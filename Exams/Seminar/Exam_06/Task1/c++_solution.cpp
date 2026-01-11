#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int index;
    int weightToNode;

    bool operator<(const Node& other) const {
        return weightToNode > other.weightToNode;
    }
};

int main() {
    int V, E;
    int src, target;
    cin >> V >> E >> src >> target;
    vector<int> times(V, 0);
    for (size_t i = 0; i < V; i++) {
        cin >> times[i];
    }
    unordered_map<int, vector<Edge>> graph;
    for (size_t i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to, weight });
    }

    vector<int> results(V, INT_MAX);
    results[src] = 0;
    priority_queue<Node> pq;
    pq.push({ src, 0 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.index == target) {
            break;
        }

        if (curr.weightToNode > results[curr.index]) {
            continue;
        }

        for (auto& adj : graph[curr.index]) {
            int weight = curr.weightToNode + adj.weight;
            int waitingTime = times[adj.to] - weight % times[adj.to];
            if (waitingTime == times[adj.to] || adj.to == target) {
                waitingTime = 0;
            }

            int newDistance = weight + waitingTime;
            if (newDistance < results[adj.to]) {
                results[adj.to] = newDistance;
                pq.push({ adj.to, newDistance });
            }
        }
    }

    if (results[target] == INT_MAX) {
        std::cout << -1;
    }
    else {
        cout << results[target];
    }
}