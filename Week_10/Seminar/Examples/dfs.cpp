#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(int current, unordered_set<int> &visited, unordered_map<int, unordered_set<int>> &graph)
{
    cout << current << " ";
    visited.insert(current);

    for (int neighbor : graph[current])
    {
        if (!visited.count(neighbor))
        {
            dfs(neighbor, visited, graph);
        }
    }
}

int main()
{
    unordered_map<int, unordered_set<int>> graph = {
        {0, {1, 2, 3}},
        {1, {0, 2, 4}},
        {2, {0, 1}},
        {3, {0, 5}},
        {4, {1, 5}},
        {5, {3, 4, 6}},
        {6, {5}}};

    unordered_set<int> visited;
    dfs(0, visited, graph); // 0 3 5 6 4 1 2
    return 0;
}
