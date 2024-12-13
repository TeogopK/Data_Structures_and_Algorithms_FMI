class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, bool> visited;

        for (auto& e : edges) {
            if (visited.count(e[0]) != 0)
                return e[0];
            if (visited.count(e[1]) != 0)
                return e[1];
            visited[e[0]] = true;
            visited[e[1]] = true;
        }

        return -1;
    }
};