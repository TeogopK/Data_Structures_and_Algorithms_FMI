#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto &t : times)
        {
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
            {
                continue;
            }

            for (auto &[v, w] : graph[u])
            {
                int new_dist = dist[u] + w;
                if (new_dist < dist[v])
                {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};