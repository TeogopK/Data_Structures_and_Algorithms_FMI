class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    void dfs(int curr) {
        visited.insert(curr);
        for(auto adj: graph[curr]) {
            if(!visited.count(adj)) {
                dfs(adj);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) {
            return -1;
        }

        for(auto& edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int numberOfConnectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                numberOfConnectedComponents++;
                dfs(i);
            }
        }

        return numberOfConnectedComponents - 1;
    }
};