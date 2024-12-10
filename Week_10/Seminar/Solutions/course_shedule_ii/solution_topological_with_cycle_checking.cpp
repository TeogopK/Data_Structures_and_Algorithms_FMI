class Solution
{
public:
    bool dfs(int current, std::unordered_map<int, int> &colours, std::vector<int> &topologicalStack, std::unordered_map<int, std::unordered_set<int>> &graph)
    {
        colours[current] = 1;

        for (int neighbor : graph[current])
        {
            if (colours[neighbor] == 1)
            {
                return true;
            }

            if (colours[neighbor] == 2)
            {
                continue;
            }

            if (dfs(neighbor, colours, topologicalStack, graph))
            {
                return true;
            }
        }

        colours[current] = 2;
        topologicalStack.push_back(current);

        return false;
    }

    std::vector<int> hasCycleWithTopological(std::unordered_map<int, std::unordered_set<int>> &graph)
    {
        std::vector<int> topologicalStack;
        std::unordered_map<int, int> colours;

        for (auto it = graph.cbegin(); it != graph.cend(); it++)
        {
            if (colours.count(it->first) != 0)
            {
                continue;
            }

            if (dfs(it->first, colours, topologicalStack, graph))
            {
                return {};
            }
        }

        std::reverse(topologicalStack.begin(), topologicalStack.end());

        return topologicalStack;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Note that this solution is not efficient, since we are traversing twice the graph
        std::unordered_map<int, std::unordered_set<int>> graph;

        for (int i = 0; i < numCourses; i++)
        {
            graph[i] = {};
        }

        int v, w;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            v = prerequisites[i][0];
            w = prerequisites[i][1];

            // Its reversed: v needs w
            graph[w].insert(v);
        }

        return hasCycleWithTopological(graph);
    }
};