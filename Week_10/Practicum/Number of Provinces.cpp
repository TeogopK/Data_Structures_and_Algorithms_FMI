class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int curr, vector<bool>& visited) {
        visited[curr] = true;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[curr][j] == 1 && !visited[j]) {
                dfs(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int counter = 0;

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                counter++;
                dfs(isConnected, i, visited);
            }
        }
        return counter;
    }
};