#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * Performs topological sorting using DFS with marking (coloring).
 * Uses three states: 'u' (unopened/unvisited), 'o' (opened/in progress), 'c' (closed/finished).
 * Detects cycles using 'o' (opened) nodes. If we open and node and later encounter it again while it's still 'o', a cycle exists.
 * Result: A linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v.
 */

bool dfsTopoSort(
    int current,
    std::unordered_map<int, std::vector<int>>& graph,
    std::vector<char>& visited,
    std::vector<int>& result
) {
    // If already finished, return true
    if (visited[current] == 'c') {
        return true;
    }

    // If opened (in progress), we have a cycle
    if (visited[current] == 'o') {
        return false;
    }

    // Mark as opened (in progress)
    visited[current] = 'o';

    // Traverse all neighbors
    for (int neighbor : graph.at(current)) {
        if (!dfsTopoSort(neighbor, graph, visited, result)) {
            return false; // Cycle detected
        }
    }

    // Add to result and mark as finished
    result.push_back(current);
    visited[current] = 'c';

    return true;
}

std::vector<int> topologicalSortWithMarking(int V, std::unordered_map<int, std::vector<int>>& graph) {
    std::vector<char> visited(V, 'u'); // 'u' - unopened
    std::vector<int> result;

    // Traverse all vertices
    for (int i = 0; i < V; i++) {
        if (visited[i] == 'u') {
            if (!dfsTopoSort(i, graph, visited, result)) {
                return {}; // Graph has a cycle
            }
        }
    }

    // Result is in reverse topological order, so reverse it
    std::reverse(result.begin(), result.end());

    return result;
}

int main() {
    // Example: DAG with 6 vertices
    std::unordered_map<int, std::vector<int>> graph = {
        {5, {2, 0}},
        {4, {0, 1}},
        {2, {3}},
        {3, {1}}
    };

    int V = 6;
    std::vector<int> result = topologicalSortWithMarking(V, graph);

    if (result.empty()) {
        std::cout << "Graph has a cycle!\n";
    }
    else {
        std::cout << "Topological order: ";
        for (int node : result) {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }

    return 0;
}