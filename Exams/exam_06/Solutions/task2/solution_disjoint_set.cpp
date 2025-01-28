#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    long long weight;
};

class UnionFind
{
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int verticesCount)
    {
        parent.resize(verticesCount + 1);
        rank.resize(verticesCount + 1);

        for (int i = 1; i <= verticesCount; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void union_sets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
        {
            return;
        }

        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (rank[rootY] > rank[rootX])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

unordered_set<int> visitedComponents;
unordered_map<int, vector<Edge>> graph;
vector<Edge> edges;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int v, e;
    std::cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        long long w;
        std::cin >> v1 >> v2 >> w;

        edges.push_back({v1, v2, w});
        edges.push_back({v2, v1, w});
    }

    UnionFind uf(v);
    int componentsCount = v;

    std::sort(edges.begin(), edges.end(), [](const Edge &lhs, const Edge &rhs)
              { return lhs.weight > rhs.weight; });

    long long totalSum = 0;
    for (const auto &edge : edges)
    {

        if (uf.find(edge.from) != uf.find(edge.to))
        {
            totalSum += edge.weight;
            uf.union_sets(edge.from, edge.to);
            componentsCount--;
        }
    }
    std::cout << componentsCount << " " << totalSum << std::endl;
}