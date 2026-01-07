#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_set<int> visited;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited.insert(start);

    int edgeCount = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // every edge will be counted twice
        edgeCount += graph[node].size();

        for (int adj : graph[node]) {
            if (!visited.count(adj)) {
                visited.insert(adj);
                q.push(adj);
            }
        }
    }

    return edgeCount / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    int v1, v2;
    for (int i = 0; i < E; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    vector<int> result;
    for (int i = 0; i < V; i++) {
        if (!visited.count(i)) {
            result.push_back(bfs(i));
        }
    }

    sort(result.begin(), result.end());
    for (int count : result) {
        cout << count << " ";
    }

    return 0;
}
