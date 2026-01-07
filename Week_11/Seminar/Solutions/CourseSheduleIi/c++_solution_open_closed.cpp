class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        // o - opened
        // c - closed
        // u - unopened
        vector<char> visited(numCourses, 'u'); 

        for(const auto& req: prerequisites){
            graph[req[0]].push_back(req[1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 'u') {
                if(!dfs(graph, visited, i)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs(const vector<vector<int>>& graph, vector<char>& visited, int current) {
        if(visited[current] == 'c'){
            return true;
        }
        if(visited[current] == 'o') {
            return false;
        }

        visited[current] = 'o';

        for(const auto& node: graph[current]) {
            if(!dfs(graph, visited, node)){
                return false;
            }
        }

        visited[current] = 'c';

        return true;
    }
};
