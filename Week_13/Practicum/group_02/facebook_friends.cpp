#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph, int& nodes) {
    visited[node] = true;
    
    for(int adj : graph[node]) {
        if(!visited[adj]) {
            dfs(adj, visited, graph, ++nodes);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, e, k;
    cin >> n >> e >> k;
    
    vector<vector<int>> graph(n);
    
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<bool> visited(n);
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            int nodes = 1;
            dfs(i, visited, graph, nodes);
            if(nodes % k == 0) {
                count++;
            }
        }
    }
    
    cout << count;
    
    
    return 0;
}
