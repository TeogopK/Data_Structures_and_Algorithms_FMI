class Solution {
    // mark every node with color => red and blue
    bool dfs(int current, unordered_map<int, unordered_set<int>>& graph, unordered_map<int, bool>& colors, bool currentColor = true) {
        auto iter = colors.find(current);
        if(iter != colors.end()) {
            return iter->second == currentColor;
        } 
        
        colors[current] = currentColor;
        for(auto& neighbour: graph[current]) {
            if(!dfs(neighbour, graph, colors, !currentColor)) {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> graph;
        for(auto& edge: dislikes) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        unordered_map<int, bool> colors;
        for(auto& kvp: graph) {
            auto iter = colors.find(kvp.first);
            if(iter == colors.end()) {
                if(!dfs(kvp.first, graph, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
};
