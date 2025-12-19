#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

// This is global, we must clean it after each calling of the solve method
std::unordered_map<int, std::unordered_set<int>> graph;

void bfs(int starting_vertex, std::unordered_set<int> &visited, std::unordered_map<int, std::unordered_set<int>> &graph)
{
    std::queue<int> q;
    q.push(starting_vertex);
    visited.insert(starting_vertex);

    while (!q.empty())
    {
        // No need for levels
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current])
        {
            if (!visited.count(neighbor))
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int solve()
{
    int V, E;
    std::cin >> V >> E;

    // Create all vertexes in the graph
    for (int v = 0; v < V; v++)
    {
        graph[v];
    }

    // Connect some of the vertexes in the graph from the edges list
    int v, w;
    for (int e = 0; e < E; e++)
    {
        std::cin >> v >> w;
        graph[v].insert(w);
        graph[w].insert(v);
    }

    std::unordered_set<int> visited;
    int count = 0;

    for (auto it = graph.cbegin(); it != graph.cend(); it++)
    {
        if (visited.count(it->first) != 0)
        {
            continue;
        }
        bfs(it->first, visited, graph);
        count++;
    }

    graph.clear();

    return count;
}

int main()
{
    // Enough to speed up the input so the last test passes
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        int answer = solve();
        std::cout << answer << " ";
    }

    return 0;
}
