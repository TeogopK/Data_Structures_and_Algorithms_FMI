#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

void printResults(const size_t start, const std::vector<int> &results)
{
    int multiplier = 6;
    int distance;

    for (size_t v = 1; v < results.size(); v++)
    {
        if (v == start)
        {
            continue;
        }
        distance = results[v] ? results[v] * multiplier : -1;
        std::cout << distance << " ";
    }
    std::cout << "\n";
}

void bfs(const int start, std::vector<int> &results, std::unordered_map<int, std::unordered_set<int>> &graph)
{
    std::queue<int> q;
    q.push(start);

    std::unordered_set<int> visited;
    visited.insert(start);

    int level = 0;
    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            int current = q.front();
            q.pop();

            results[current] = level;

            const auto children = graph[current];
            for (auto it = children.cbegin(); it != children.cend(); it++)
            {
                if (!visited.count(*it))
                {
                    q.push(*it);
                    visited.insert(*it);
                }
            }
        }

        level++;
    }
}

int main()
{
    int Q;
    std::cin >> Q;

    while (Q--)
    {
        std::unordered_map<int, std::unordered_set<int>> graph;

        int V, E, start, v, w;
        std::cin >> V >> E;

        for (int i = 1; i <= V; i++)
        {
            graph[i];
        }

        for (int i = 0; i < E; i++)
        {
            std::cin >> v >> w;
            graph[v].insert(w);
            graph[w].insert(v);
        }
        std::cin >> start;

        // vertex 0 does not exist, so we will ignore the first position
        std::vector<int> results(V + 1);

        bfs(start, results, graph);
        printResults(start, results);
    }

    return 0;
}