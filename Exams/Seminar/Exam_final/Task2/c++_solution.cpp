#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;
int n, m;

bool hasPath(int start, int end, int forbidden) {
    bool visited[1001] = { false };

    queue<int> q;
    q.push(start);
    visited[start] = true;
    visited[forbidden] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int adj : graph[curr]) {
            if (visited[adj]) {
                continue;
            }
            if (adj == end) {
                return true;
            }
            visited[adj] = true;
            q.push(adj);
        }
    }

    return false;
}

bool isCrossroad(int O) {
    if (graph[O].size() != 4) {
        return false;
    }

    int A = graph[O][0];
    int B = graph[O][1];
    int C = graph[O][2];
    int D = graph[O][3];

    // ab cd
    return (hasPath(A, B, O) && hasPath(C, D, O))
        // ac bd
        || (hasPath(A, C, O) && hasPath(B, D, O))
        // ad bc
        || (hasPath(A, D, O) && hasPath(B, C, O));
}

int main() {
    int q;
    cin >> q;

    int totalCrossroads = 0;

    while (q--) {
        cin >> n >> m;
        graph.clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (isCrossroad(i)) {
                totalCrossroads++;
                break;
            }
        }
    }

    cout << totalCrossroads << endl;
}
