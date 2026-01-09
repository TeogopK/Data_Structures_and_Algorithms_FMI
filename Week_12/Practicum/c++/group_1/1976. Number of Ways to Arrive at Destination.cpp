#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const int MOD = 1000000007;

        vector<vector<pair<int, int>>> graph(n);
        for (auto &r : roads)
        {
            int u = r[0], v = r[1], w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            long long curr_dist = pq.top().first;
            int curr_node = pq.top().second;

            pq.pop();

            if (curr_dist != dist[curr_node])
            {
                continue;
            }

            for (auto neigh : graph[curr_node])
            {
                int neigh_node = neigh.first;
                long long new_dist = curr_dist + neigh.second;

                if (new_dist < dist[neigh_node])
                {
                    dist[neigh_node] = new_dist;
                    ways[neigh_node] = ways[curr_node];
                    pq.push({new_dist, neigh_node});
                }
                else if (new_dist == dist[neigh_node])
                {
                    ways[neigh_node] = (ways[neigh_node] + ways[curr_node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
