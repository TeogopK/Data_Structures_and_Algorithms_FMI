#include <bits/stdc++.h>
using namespace std;

const int INF = -1;
unordered_map<int, unordered_map<int, int>> graph;

void printSolution(vector<int>& results, int start, int v)
{
    for (int i = 1; i <= v; i++)
    {
        if (i == start)
        {
            continue;
        }

        cout << results[i] << " ";
    }
}

void dijkstra(int start, int v)
{
    vector<int> results(v + 1, INF);
    results[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    unordered_set<int> visited;
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int dist, to;
        dist = curr.first;
        to = curr.second;

        if (visited.count(to))
        {
            continue;
        }
        visited.insert(to);

        for (auto& it : graph[to])
        {
            int nbr, edgeWeight;
            nbr = it.first;
            edgeWeight = it.second;

            if (visited.count(nbr))
            {
                continue;
            }

            if (results[nbr] == INF || dist + edgeWeight < results[nbr])
            {
                results[nbr] = dist + edgeWeight;
                pq.push({ results[nbr], nbr });
            }
        }
    }

    printSolution(results, start, v);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        graph[i];
    }

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;

        if (graph[v].count(u) && graph[v][u] <= w)
        {
            continue;
        }

        graph[v][u] = w;
        graph[u][v] = w;
    }

    int start;
    cin >> start;

    dijkstra(start, n);

    return 0;
}
