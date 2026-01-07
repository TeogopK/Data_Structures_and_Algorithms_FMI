class Solution {
    unordered_set<int> visited;

    void dfs(int curr, vector<vector<int>>& isConnected) {
        visited.insert(curr);
        for(size_t i = 0; i < isConnected.size(); i++) {
            if(isConnected[curr][i] && !visited.count(i)) {
                dfs(i, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int components = 0;
        for(size_t i = 0; i < n; i++) {
            if(!visited.count(i)) {
                dfs(i, isConnected);
                components++;
            }
        }

        return components;
    }
};
