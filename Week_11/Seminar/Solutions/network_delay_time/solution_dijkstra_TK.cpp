class Solution
{
public:
    const int INF = -1;

    int calculateMaxDistance(const std::vector<int> &results)
    {
        // First cell is not used
        if (std::find(results.begin() + 1, results.end(), INF) != results.end())
        {
            return -1;
        }
        return *std::max_element(results.begin(), results.end());
    }

    int dijkstra(std::unordered_map<int, std::unordered_map<int, int>> &graph, const int start, const int V)
    {
        std::vector<int> results(V + 1, INF);
        results[start] = 0;

        std::unordered_set<int> visited;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, start));

        while (!pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            int currentDistance, v;
            currentDistance = current.first;
            v = current.second;

            if (visited.count(v))
            {
                continue;
            }
            visited.insert(v);

            for (auto it = graph[v].cbegin(); it != graph[v].cend(); it++)
            {
                int u, vertexDistance;
                u = it->first;
                vertexDistance = it->second;

                if (visited.count(u))
                {
                    continue;
                }

                if (results[u] == INF || currentDistance + vertexDistance < results[u])
                {
                    results[u] = currentDistance + vertexDistance;
                    pq.push(std::make_pair(results[u], u));
                }
            }
        }

        return calculateMaxDistance(results);
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        std::unordered_map<int, std::unordered_map<int, int>> graph;

        for (int i = 1; i <= n; i++)
        {
            graph[i];
        }

        int v, u, w;

        for (int i = 0; i < times.size(); i++)
        {
            v = times[i][0];
            u = times[i][1];
            w = times[i][2];

            // Directed
            graph[v][u] = w;
        }

        return dijkstra(graph, k, n);
    }
};