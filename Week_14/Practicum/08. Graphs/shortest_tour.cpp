#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& pathSet, int from, int to)
{
    unordered_set<int> visited;
    queue<int> q;

    q.push(from);
    visited.insert(from);

    int dist = 0;
    while (!q.empty())
    {
        dist++;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto curr = q.front();
            q.pop();

            for (auto& nbr : graph[curr])
            {
                if (nbr == to)
                {
                    return dist;
                }

                if (visited.count(nbr) == 0 && pathSet.count(nbr) == 0)
                {
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> graph;

    for (int i = 0; i < n; i++)
    {
        graph[i];
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
    }

    int k;
    cin >> k;

    vector<int> path(k);
    for (int i = 0; i < k; i++)
    {
        cin >> path[i];
    }

    unordered_set<int> pathSet(path.begin(), path.end());
    int res = 0;
    pathSet.erase(path[0]);

    for (int i = 0; i < k - 1; i++)
    {
        pathSet.erase(path[i + 1]);
        int len = bfs(graph, pathSet, path[i], path[i + 1]);

        if (len == -1)
        {
            cout << -1;
            return 0;
        }

        else
        {
            res += len;
        }
    }

    cout << res;
    return 0;
}
