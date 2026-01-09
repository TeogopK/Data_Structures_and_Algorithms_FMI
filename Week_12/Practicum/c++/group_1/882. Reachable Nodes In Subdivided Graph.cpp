#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges)
        {
            graph[e[0]].push_back({e[1], e[2] + 1});
            graph[e[1]].push_back({e[0], e[2] + 1});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            long long curr_dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (curr_dist != dist[node])
            {
                continue;
            }

            for (auto &neigh : graph[node])
            {
                int neigh_node = neigh.first;
                long long new_dist = curr_dist + neigh.second;
                if (new_dist < dist[neigh_node])
                {
                    dist[neigh_node] = new_dist;
                    pq.push({new_dist, neigh_node});
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] <= maxMoves)
            {
                res++;
            }
        }

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], weight = e[2];

            long long a = (dist[u] <= (long long)maxMoves) ? (long long)maxMoves - dist[u] : 0;
            long long b = (dist[v] <= (long long)maxMoves) ? (long long)maxMoves - dist[v] : 0;

            res += min<long long>(weight, a + b);
        }

        return (int)res;
    }
};