// Converted from Python to C++
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> topological_bfs(const std::unordered_map<int, std::unordered_set<int>> &graph)
    {
        // Step 1: Compute in-degree of each vertex
        std::unordered_map<int, int> in_degree;
        for (const auto &[vertex, _] : graph)
        {
            in_degree[vertex] = 0; // Initialize in-degree to 0
        }
        for (const auto &[vertex, children] : graph)
        {
            for (int child : children)
            {
                in_degree[child]++;
            }
        }

        // Step 2: Initialize the queue with vertices of in-degree 0
        std::queue<int> q;
        std::vector<int> order;
        for (const auto &[vertex, degree] : in_degree)
        {
            if (degree == 0)
            {
                q.push(vertex);
                order.push_back(vertex);
            }
        }

        // Step 3: Perform BFS
        std::unordered_set<int> visited(order.begin(), order.end());
        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor : graph.at(current))
            {
                if (visited.find(neighbor) == visited.end())
                {
                    in_degree[neighbor]--;
                }

                if (in_degree[neighbor] == 0)
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                    order.push_back(neighbor);
                }
            }
        }

        return order;
    }

    std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>> &prerequisites)
    {
        // Step 1: Build the graph
        std::unordered_map<int, std::unordered_set<int>> graph;

        for (int i = 0; i < numCourses; ++i)
        {
            graph[i] = {};
        }

        for (const auto &edge : prerequisites)
        {
            int advanced = edge[0];
            int beginner = edge[1];
            graph[beginner].insert(advanced);
        }

        // Step 2: Get the topological order
        std::vector<int> order = topological_bfs(graph);

        // If the order does not contain all courses, there is a cycle
        return order.size() == numCourses ? order : std::vector<int>();
    }
};