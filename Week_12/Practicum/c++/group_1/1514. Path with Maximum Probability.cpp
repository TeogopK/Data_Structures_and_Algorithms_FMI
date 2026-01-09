#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());

        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            double prob = succProb[j];
            if (u != v)
            {
                graph[u].push_back({v, prob});
                graph[v].push_back({u, prob});
            }
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (node == end_node)
            {
                return prob;
            }

            if (prob < maxProb[node])
            {
                continue;
            }

            for (auto &neigh : graph[node])
            {
                double newProb = prob * neigh.second;
                if (newProb > maxProb[neigh.first])
                {
                    maxProb[neigh.first] = newProb;
                    pq.push({newProb, neigh.first});
                }
            }
        }

        return 0.0;
    }
};