class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int curr, vector<bool>& visited) {
        visited[curr] = true;
        for (auto& r : rooms[curr]) {
            if (!visited[r]) {
                dfs(rooms, r, visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        dfs(rooms, 0, visited);

        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }
};