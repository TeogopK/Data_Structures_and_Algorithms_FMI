class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        vector<int> topologicalOrder;

        // Create the adjacency list representation of the graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            adjList[src].push_back(dest);

            // Record in-degree of each vertex
            indegree[dest]++;
        }

        // Add all vertices with 0 in-degree to the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process until the queue becomes empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topologicalOrder.push_back(node);

            // Reduce the in-degree of each neighbor by 1
            if (adjList.count(node)) {
                for (auto neighbor : adjList[node]) {
                    indegree[neighbor]--;

                    // If in-degree of a neighbor becomes 0, add it to the queue
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Check to see if topological sort is possible or not
        if (topologicalOrder.size() == numCourses) {
            return topologicalOrder;
        }

        return vector<int>();
    }
};
