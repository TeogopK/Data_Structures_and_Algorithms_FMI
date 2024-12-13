class Solution {
public:
    stack<int> topo;
    
    bool dfs(int curr, vector<vector<int>>& graph, vector<int>& state) {
        // state[curr]: 0=unvisited, 1=visiting, 2=visited
        state[curr] = 1;

        for (auto& neigh : graph[curr]) {
            if (state[neigh] == 1) {
                // Found a back edge -> cycle
                return true;
            } else if (state[neigh] == 0) {
                if (dfs(neigh, graph, state)) {
                    return true; // cycle found in deeper call
                }
            }
        }

        state[curr] = 2;
        topo.push(curr);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
        }

        vector<int> state(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, graph, state)) { // Cycle detected
                    return {};
                }
            }
        }

        vector<int> result;
        while (!topo.empty()) {
            result.push_back(topo.top());
            topo.pop();
        }
        return result;
    }
};
