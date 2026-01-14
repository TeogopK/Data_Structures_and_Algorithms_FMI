#include <bits/stdc++.h>
using namespace std;


int main() {


    unordered_map<int, unordered_set<int>> graph;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        graph[i];
    }

    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;

        graph[f].insert(t);
        graph[t].insert(f);
    }

    int start = n;

    queue<int> q;
    q.push(start);

    unordered_set<int> visited;
    visited.insert(start);

    set<int> res;

    int dist = 0;
    while (!q.empty())
    {
        if (dist == k)
        {
            while (!q.empty())
            {
                res.insert(q.front());
                q.pop();
            }

            break;
        }

        int level = q.size();
        for (int i = 0; i < level; i++)
        {
            auto curr = q.front();
            q.pop();

            for (auto& nbr : graph[curr])
            {
                if (visited.count(nbr) == 0)
                {
                    q.push(nbr);
                    visited.insert(nbr);
                }
            }
        }

        dist++;
    }

    if (!res.size())
    {
        cout << -1;
        return 0;
    }

    for (auto& node : res)
    {
        cout << node << " ";
    }

    return 0;
}
