#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool hasCycle(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int current) {
    if(visited.count(current)) {
        return true;
    }
    
    visited.insert(current);
    for(int adj: graph[current]) {
        if(visited.count(adj)) {
            return true;
        }
        
        if(hasCycle(graph, visited, adj)) {
            return true;
        }
    }
    visited.erase(current);

    
    return false;
    
}

int main() {
    int q;
    cin >> q;
    for(size_t i = 0; i < q; i++) {
        int n, edgesCount;
        cin >> n >> edgesCount;
        int from, to, weight;
        unordered_map<int, vector<int>> graph;
        for(size_t i = 0; i < edgesCount; i++) {
            cin >> from >> to >> weight;
            graph[from].push_back(to);
        }
        unordered_set<int> visited;
        bool flag = false;
        for(size_t i = 1; i <= n; i++) {
            if(hasCycle(graph, visited, i)) {
                flag = true;
                break;
            }
        }
        
        cout << (flag ? "true" : "false") << " ";
        
    }
    return 0;
}
