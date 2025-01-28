#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_set<int> visited;
int res = 0;

int dfs(int curr)
{
    if (graph[curr].size() == 0)
    {
        return 1;
    }

    visited.insert(curr);
    int children = 1;

    for (auto& nbr : graph[curr])
    {
        if (visited.count(nbr) == 0)
        {
            children += dfs(nbr);
        }
    }

    if (children % 2 == 0)
    {
        res++;
        return 0;
    }

    return children;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        graph[i];
    }

    for (int i = 0; i < e; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].insert(u);
        graph[u].insert(v);
    }

    dfs(1);

    cout << res - 1;

    return 0;
}
