class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    bool dfs(int current, int destination) {
        if(current == destination) {
            return true;
        }

        visited.insert(current);
        for(int adj: graph[current]) {
            if(!visited.count(adj)) {
                if(dfs(adj, destination)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool bfs(int start, int destination) {
        queue<int> q;
        q.push(start);
        visited.insert(start);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr == destination) {
                return true;
            }
            
            for(int adj: graph[curr]) {
                if(!visited.count(adj)) {
                    visited.insert(adj);
                    q.push(adj);
                }
            }
        }

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto& edge: edges) {
            // x y
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        return bfs(source, destination);

        //return found;
        // source // dfs/bfs
        // destination
    }
};
