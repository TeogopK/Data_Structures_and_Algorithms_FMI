
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

    
unordered_map<size_t, unordered_set<size_t>> graph;
unordered_set<size_t> forbidden;

size_t minPath(size_t from, size_t to) {
    queue<size_t> next;
    unordered_set<size_t> visited;
    next.push(from);
    visited.insert(from);
    
    size_t currentLevel = 0;
    
    while(!next.empty()) {
        size_t levelSize = next.size();
        
        for(size_t i = 0; i < levelSize; i++) {
            size_t current = next.front();
            next.pop();
            
            if(current == to) {
                return currentLevel;
            }
            
            for(auto adj: graph[current]) {
                if(!visited.count(adj) && !forbidden.count(adj)) {
                    visited.insert(adj);
                    next.push(adj);
                }
            }
        }
        
        currentLevel++;
    }
    
    return 0;
}

int main() {
    size_t nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;
    
    for(size_t i = 0; i < edgesCount; i++) {
        size_t from, to;
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }
    
    
    size_t pathLength;
    cin >> pathLength;
    vector<size_t> path(pathLength);
    for(size_t i = 0; i < pathLength; i++) {
        cin >> path[i];
    }
    
    size_t forbiddenLength;
    cin >> forbiddenLength;
    for(size_t i = 0; i < forbiddenLength; i++) {
        size_t k;
        cin >> k;
        forbidden.insert(k);
    }
    
    for(size_t i = 1; i < path.size(); i++) {
        forbidden.insert(path[i]);
    }
    
    size_t result = 0;
    
    for(size_t i = 1; i < path.size(); i++) {
        forbidden.erase(path[i]);
        result += minPath(path[i - 1], path[i]);
    }
    
    cout << result;
    
}
