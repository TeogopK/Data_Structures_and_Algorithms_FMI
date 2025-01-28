#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t dfs(size_t curr, const vector<vector<size_t>>& adj, vector<bool>& visited, size_t& res)
{
    visited[curr] = true;
    
    size_t currCount = 1;

    for(auto child: adj[curr])
    {
        if(!visited[child])
        {
            currCount += dfs(child, adj, visited, res);
        }
    }
    
    if(currCount % 2 == 0)
    {
        res++;
    }
    
    return currCount;
}

int main() {
    size_t V, E;
    cin >> V >> E;
    
    vector<vector<size_t>> adj(V, vector<size_t>());
    vector<bool> visited(V, false);
    for(size_t i = 0; i < E; i++)
    {
        size_t from, to;
        cin >> from >> to;
        adj[from - 1].push_back(to - 1);
        adj[to - 1].push_back(from - 1);
    }

    size_t result = 0;
    for(size_t i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            dfs(i, adj, visited, result);
        }
    }
    
    cout << result - 1;
}