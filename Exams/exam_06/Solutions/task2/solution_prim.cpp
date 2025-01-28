#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    long long from;
    long long to;
    long long weight;

    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

long long prim(long long start, unordered_set<long long> &visited, unordered_map<long long, vector<Edge>> &graph)
{
    priority_queue<Edge> pq;
    pq.push({start, start, 0});

    long long totalWeight = 0;

    while (!pq.empty())
    {
        Edge current = pq.top();
        pq.pop();

        if (visited.count(current.to))
        {
            continue;
        }

        visited.insert(current.to);
        totalWeight += current.weight;
        for (auto neighbor : graph[current.to])
        {
            if (!visited.count(neighbor.to))
            {
                pq.push(neighbor);
            }
        }
    }

    return totalWeight;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    unordered_set<long long> visited;

    unordered_map<long long, vector<Edge>> graph;

    long long nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    if (nodesCount == 1)
    {
        cout << 1 << " " << 0;
        return 0;
    }

    for (long long i = 1; i <= nodesCount; i++)
    {
        graph[i];
    }

    for (long long i = 0; i < edgesCount; i++)
    {
        long long from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back({from, to, weight});
        graph[to].push_back({to, from, weight});
    }

    long long components = 0;
    long long totalWeight = 0;

    for (long long i = 1; i <= nodesCount; i++)
    {
        if (!visited.count(i))
        {
            components++;
            long long currentWeight = prim(i, visited, graph);
            totalWeight += currentWeight;
        }
    }

    cout << components << " " << totalWeight;
    return 0;
}