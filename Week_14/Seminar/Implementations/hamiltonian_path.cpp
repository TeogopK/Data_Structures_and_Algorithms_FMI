#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool dfs(std::unordered_map<int, std::unordered_set<int>>& graph, std::unordered_set<int>& visited, int current, int totalVertices) {
    visited.insert(current);
    if (visited.size() == totalVertices) {
        // if you are checking for cycle
        // if (graph[current].count(start)) {
        //     return true;
        // }
        return true;
    }

    for (int neighbor : graph[current]) {
        if (!visited.count(neighbor) && dfs(graph, visited, neighbor, totalVertices)) {
            return true;
        }
    }

    visited.erase(current);
    return false;
}

bool hasHamiltonPath(std::unordered_map<int, std::unordered_set<int>>& graph, int start) {
    std::unordered_set<int> visited;
    int totalVertices = graph.size();

    visited.insert(start);

    return dfs(graph, visited, start, totalVertices);
}


int main() {

}
