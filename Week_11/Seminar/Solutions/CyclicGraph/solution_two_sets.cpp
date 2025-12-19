#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>

// This is global, we must clean it after each calling of the solve method
std::unordered_map<int, std::unordered_set<int>> graph;

bool dfs(int current, std::unordered_set<int> &inProgress, std::unordered_set<int> &visited, std::unordered_map<int, std::unordered_set<int>> &graph)
{
    visited.insert(current);
    inProgress.insert(current);

    for (int neighbor : graph[current])
    {
        if (inProgress.count(neighbor))
        {
            return true;
        }

        if (visited.count(neighbor))
        {
            continue;
        }

        if (dfs(neighbor, inProgress, visited, graph))
        {
            return true;
        }
    }
    inProgress.erase(current);

    return false;
}

bool hasCycle(std::unordered_map<int, std::unordered_set<int>> &graph)
{
    std::unordered_set<int> visited;

    for (auto it = graph.cbegin(); it != graph.cend(); it++)
    {
        // Cleaned each time
        std::unordered_set<int> inProgress;

        if (visited.count(it->first) != 0)
        {
            continue;
        }

        if (dfs(it->first, inProgress, visited, graph))
        {
            return true;
        }
    }
    return false;
}

bool solve()
{
    int V, E;
    std::cin >> V >> E;

    // Create all vertexes in the graph
    for (int v = 1; v <= V; v++)
    {
        graph[v];
    }

    // Connect some of the vertexes in the graph from the edges list
    int x, y, w;
    for (int e = 0; e < E; e++)
    {
        // Note that w is not used
        std::cin >> x >> y >> w;

        // Note that the graph is directed
        graph[x].insert(y);
    }

    bool answer = hasCycle(graph);
    graph.clear();

    return answer;
}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        auto answer = solve() ? "true" : "false";
        std::cout << answer << " ";
    }

    return 0;
}