#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_set<int> visited;

void dfs(int node, long long& edgeCount) {
    visited.insert(node);
    // every edge will be counted twice
    edgeCount += graph[node].size();
    
    for(int adj: graph[node]) {
        if(!visited.count(adj)) {
            dfs(adj, edgeCount);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;
    
    int v1, v2;
    for(int i = 0; i < E; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    vector<long long> result;
    for(int i = 0; i < V; i++) {
        if(!visited.count(i)) {
            long long edgeCount = 0;
            dfs(i, edgeCount);
            result.push_back(edgeCount / 2);
        }
    }
    
    sort(result.begin(), result.end());
    for(auto count: result) {
        std::cout << count << " ";
    }
}
