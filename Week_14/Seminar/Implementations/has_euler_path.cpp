#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// For undirected graph

bool hasEulerCircuit(unordered_map<int, vector<int>>& graph) {
    for (auto& [node, neighbors] : graph) {
        // Euler circuit: all vertices have even degree
        if (neighbors.size() % 2 != 0) {
            return false;
        }
    }
    return true;
}

bool hasEulerPath(unordered_map<int, vector<int>>& graph) {
    int oddDegreeCount = 0;

    for (auto& [node, neighbors] : graph) {
        if (neighbors.size() % 2 == 1) {
            oddDegreeCount++;
        }
    }

    // Euler path: exactly 0 or 2 vertices have odd degree
    return oddDegreeCount == 0 || oddDegreeCount == 2;
}

// For directed graph

bool hasEulerCircuitDirected(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& inDegree, unordered_map<int, int>& outDegree) {
    for (auto& [node, neighbors] : graph) {
        // Euler circuit: inDegree == outDegree for all vertices
        if (inDegree[node] != outDegree[node]) {
            return false;
        }
    }
    return true;
}

bool hasEulerPathDirected(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& inDegree, unordered_map<int, int>& outDegree) {
    int startNodes = 0, endNodes = 0;
    for (auto& [node, neighbors] : graph) {
        if (outDegree[node] - inDegree[node] == 1) {
            startNodes++;
        }
        else if (inDegree[node] - outDegree[node] == 1) {
            endNodes++;
        }
        else if (inDegree[node] != outDegree[node]) {
            return false;
        }
    }

    // Euler path: exactly one vertex has (outDegree - inDegree) = 1 and exactly one vertex has (inDegree - outDegree) = 1
    // or all vertices have equal inDegree and outDegree
    return (startNodes == 0 && endNodes == 0) || (startNodes == 1 && endNodes == 1);
}