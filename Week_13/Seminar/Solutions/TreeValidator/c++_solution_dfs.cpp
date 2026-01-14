#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> graph;
unordered_set<int> visited;

bool hasCycle(int node, int parent) {
    visited.insert(node);

    for (int neighbor : graph[node]) {
        if (neighbor == parent) {
            continue;
        }

        if (visited.count(neighbor)) {
            return true;
        }

        if (hasCycle(neighbor, node)) {
            return true;
        }
    }

    return false;
}

bool isTree(int v, int e) {
    // A tree must have exactly v - 1 edges
    if (e != v - 1) {
        return false;
    }

    visited.clear();

    // Check if the graph is connected and acyclic
    // Start DFS from node 0 (assuming nodes are 0-indexed)
    if (hasCycle(0, -1)) {
        return false;
    }

    // Check if all vertices are visited (connected)
    return visited.size() == v;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, e;
        cin >> v >> e;

        graph.clear();

        for (int j = 0; j < e; j++) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        cout << isTree(v, e) << endl;
    }

    return 0;
}
