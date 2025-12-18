#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

void topological_dfs(int current, unordered_set<int> &visited, vector<int> &stack, unordered_map<int, unordered_set<int>> &graph)
{
    visited.insert(current);

    for (int neighbor : graph[current])
    {
        if (!visited.count(neighbor))
        {
            topological_dfs(neighbor, visited, stack, graph);
        }
    }
    stack.push_back(current);
}

vector<int> topological_sort(unordered_map<int, unordered_set<int>> &graph)
{
    vector<int> stack;
    unordered_set<int> visited;

    for (auto iter = graph.begin(); iter != graph.end(); ++iter)
    {
        int vertex = iter->first;
        if (!visited.count(vertex))
        {
            topological_dfs(vertex, visited, stack, graph);
        }
    }

    std::reverse(stack.begin(), stack.end());

    return stack;
}

int main()
{
    unordered_map<int, unordered_set<int>> graph = {
        {1, {2, 4}},
        {2, {3}},
        {3, {}},
        {4, {2, 5, 6}},
        {5, {6}},
        {6, {}}};

    vector<int> sorted = topological_sort(graph);
    for (int vertex : sorted)
    {
        cout << vertex << " "; // 1 4 2 3 5 6
    }
    return 0;
}
