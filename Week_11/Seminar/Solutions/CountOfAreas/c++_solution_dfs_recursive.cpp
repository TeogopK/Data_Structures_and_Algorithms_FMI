#include <iostream>
#include <unordered_set>
#include <unordered_map>

// This is global, we must clean it after each calling of the solve method
// Try without global graph and see if the last test passes
std::unordered_map<int, std::unordered_set<int>> graph;

void dfs(int current, std::unordered_set<int> &visited, std::unordered_map<int, std::unordered_set<int>> &graph)
{
    visited.insert(current);

    for (int neighbor : graph[current])
    {
        if (!visited.count(neighbor))
        {
            dfs(neighbor, visited, graph);
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
        dfs(it->first, visited, graph);
        count++;
    }

    graph.clear();

    return count;
}

int main()
{
    // // Enough to speed up the input so the last test passes if the graph is not global
    // std::cin.tie(NULL);
    // std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        int answer = solve();
        std::cout << answer << " ";
    }

    return 0;
}
