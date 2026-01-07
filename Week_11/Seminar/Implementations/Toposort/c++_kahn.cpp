#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

/**
 * Performs Kahn's algorithm for topological sorting on a directed acyclic graph (DAG).
 * Idea: Repeatedly remove nodes with no incoming edges and update the in-degrees of their neighbors.
 * Result: A linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v.
 * If the graph has a cycle, the function returns an empty vector.
 */
std::vector<int> kahnTopologicalSort(int verticesCount, std::unordered_map<int, std::vector<int>>& graph) {
    std::vector<int> inDegree(verticesCount, 0);

    // Count in-degrees of all vertices
    for (const auto& [node, neighbors] : graph) {
        for (int neighbor : neighbors) {
            inDegree[neighbor]++;
        }
    }

    // Initialize the queue with all vertices having in-degree of 0
    std::queue<int> q;
    for (int i = 0; i < verticesCount; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> topologicalOrder;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        topologicalOrder.push_back(current);

        // Decrease in-degree of neighbors
        for (int neighbor : graph[current]) {
            inDegree[neighbor]--;

            // If in-degree becomes 0, add it to the queue
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If we couldn't include all vertices, there is a cycle
    if (topologicalOrder.size() != verticesCount) {
        return {};
    }

    return topologicalOrder;
}

int main() {
    // Пример: DAG с 6 върха
    std::unordered_map<int, std::vector<int>> graph = {
        {5, {2, 0}},
        {4, {0, 1}},
        {2, {3}},
        {3, {1}}
    };

    int V = 6;
    std::vector<int> result = kahnTopologicalSort(V, graph);

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