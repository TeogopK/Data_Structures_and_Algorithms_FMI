#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
};

struct Node
{
    int index;
    int distance;

    bool operator<(const Node &other) const
    {
        return distance < other.distance;
    }
};

int djikstra(int nodes_count, int start, unordered_map<int, vector<Edge>> &graph)
{
    vector<int> distances(nodes_count, INT_MAX);
    distances[start] = 0;
    priority_queue<Node> pq;
    pq.push({start, 0});

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        if (current.distance > distances[current.index])
            continue;

        for (Edge e : graph[current.index])
        {
            int new_distance = current.distance + e.weight;
            if (new_distance < distances[e.to])
            {
                distances[e.to] = new_distance;
                pq.push({e.to, new_distance});
            }
        }
    }

    return distances[0];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, L, H, from, to;
    cin >> N >> L >> H;

    unordered_map<int, vector<Edge>> graph;

    for (int i = 0; i < L; i++)
    {
        cin >> from >> to;
        graph[from].push_back({to, 0});
        graph[to].push_back({from, 0});
    }

    for (int i = 0; i < H; i++)
    {
        cin >> from >> to;
        graph[from].push_back({to, 1});
        graph[to].push_back({from, 1});
    }

    cout << djikstra(N, N - 1, graph);
}