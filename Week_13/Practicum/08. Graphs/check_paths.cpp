#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int k;
    cin >> k;

    int from;
    cin >> from;

    int sum = 0;
    for (int i = 1; i < k; i++)
    {
        int to;
        cin >> to;

        if (graph[from][to] == -1)
        {
            cout << -1;
            return 0;
        }

        sum += graph[from][to];
        from = to;
    }

    cout << sum;
    return 0;
}
