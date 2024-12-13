class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int& vertices, int& edges) {
        visited[curr] = true;
        edges += graph[curr].size();
        vertices++;

        for (auto& n : graph[curr]) {
            if (!visited[n]) {
                dfs(graph, visited, n, vertices, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertices = 0;
                int edges = 0;
                dfs(graph,visited, i, vertices, edges);

                if (vertices * (vertices - 1) == edges) {
                    counter++;
                }
            }
        }
        return counter;
    }
};