/*
Solution using coloring with 0, 1, 2.

Nodes that are in the current dfs stack are marked with 1.
When they are exiting the stack - marked with 2.

When we visit a node that is already checked we skipped it.
When we visit a node that is already in the stack (state 1) there is a cycle.

States are:
0 - not visited
1 - in progress
2 - already checked
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>

// This is global, we must clean it after each calling of the solve method
std::unordered_map<int, std::unordered_set<int>> graph;

bool dfs(int current, std::unordered_map<int, int> &colours, std::unordered_map<int, std::unordered_set<int>> &graph)
{
    colours[current] = 1;

    for (int neighbor : graph[current])
    {
        if (colours[neighbor] == 1)
        {
            return true;
        }

        if (colours[neighbor] == 2)
        {
            continue;
        }

        if (dfs(neighbor, colours, graph))
        {
            return true;
        }
    }

    colours[current] = 2;

    return false;
}

bool hasCycle(std::unordered_map<int, std::unordered_set<int>> &graph)
{
    std::unordered_map<int, int> colours;

    for (auto it = graph.cbegin(); it != graph.cend(); it++)
    {
        if (colours.count(it->first) != 0)
        {
            continue;
        }

        if (dfs(it->first, colours, graph))
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
