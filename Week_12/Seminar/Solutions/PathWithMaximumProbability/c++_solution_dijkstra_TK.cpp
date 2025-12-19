class Solution
{
public:
    double dijkstra(std::unordered_map<int, std::unordered_map<int, double>> &graph, const int start, const int end, const int V)
    {
        const int INF = -1;

        std::vector<double> results(V, INF);
        results[start] = 0;

        std::unordered_set<int> visited;

        // Max heap
        std::priority_queue<std::pair<double, int>> pq;

        // Add 1 for start
        pq.push(std::make_pair(1, start));

        while (!pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            double currentDistance = current.first;
            int v = current.second;

            // Early exit
            if (v == end)
            {
                break;
            }

            if (visited.count(v))
            {
                continue;
            }
            visited.insert(v);

            for (auto it = graph[v].cbegin(); it != graph[v].cend(); it++)
            {
                int u = it->first;
                double vertexDistance = it->second;

                if (visited.count(u))
                {
                    continue;
                }

                // Change the comparison
                if (results[u] == INF || currentDistance * vertexDistance > results[u])
                {
                    results[u] = currentDistance * vertexDistance;
                    pq.push(std::make_pair(results[u], u));
                }
            }
        }
        return results[end] != INF ? results[end] : 0;
    }

    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        std::unordered_map<int, std::unordered_map<int, double>> graph;

        for (int i = 0; i < n; i++)
        {
            graph[i];
        }

        int v, u;
        double w;

        for (int i = 0; i < edges.size(); i++)
        {
            v = edges[i][0];
            u = edges[i][1];
            w = succProb[i];

            graph[v][u] = w;
            graph[u][v] = w;
        }

        return dijkstra(graph, start_node, end_node, n);
    }
};