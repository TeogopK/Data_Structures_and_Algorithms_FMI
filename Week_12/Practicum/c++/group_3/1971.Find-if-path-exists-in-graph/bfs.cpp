class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n, vector<int>());
        for (const auto& ed : edges) {
            adjList[ed[0]].push_back(ed[1]);
            adjList[ed[1]].push_back(ed[0]);
        }

        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int curV = q.front();
            q.pop();

            for (int adjV : adjList[curV]) {
                if (visited[adjV]) {
                    continue;
                }
                q.push(adjV);
                visited[adjV] = true;
            }
        }

        return visited[destination];
    }
};
