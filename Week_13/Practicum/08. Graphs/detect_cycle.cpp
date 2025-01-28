#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

bool cycleHelper(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, unordered_set<int>& path, int curr)
{
    visited.insert(curr);
    path.insert(curr);

    for (auto& nbr : graph[curr])
    {
        if (path.count(nbr))
        {
            return true;
        }

        if (visited.count(nbr))
        {
            continue;
        }

        if (cycleHelper(graph, visited, path, nbr))
        {
            return true;
        }
    }

    path.erase(curr);
    return false;
}

bool hasCycle(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    unordered_set<int> path;

    for (auto& it : graph)
    {
        if (visited.count(it.first) == 0 && cycleHelper(graph, visited, path, it.first))
        {
            return true;
        }
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 1; i <= v; i++)
        {
            graph[i];
        }

        for (int i = 0; i < e; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].insert(y);
        }

        cout << (hasCycle(graph) ? "true " : "false ");
        graph.clear();
    }

    return 0;
}
