#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<size_t> parents;
    vector<size_t> sizes;

    UnionFind(size_t vertices) : parents(vertices), sizes(vertices, 1)
    {
        iota(parents.begin(), parents.end(), 0);
    }

    size_t getParent(size_t vertex)
    {
        if (parents[vertex] == vertex)
        {
            return vertex;
        }

        return parents[vertex] = getParent(parents[vertex]);
    }

    bool areInOneSet(size_t first, size_t second)
    {
        return getParent(first) == getParent(second);
    }

    void unionVertices(size_t first, size_t second)
    {
        size_t parentOfFirst = getParent(first);
        size_t parentOfSecond = getParent(second);

        if (parentOfFirst == parentOfSecond)
        {
            return;
        }

        if (sizes[parentOfFirst] < sizes[parentOfSecond])
        {
            swap(parentOfFirst, parentOfSecond);
        }

        parents[parentOfSecond] = parentOfFirst;
        sizes[parentOfFirst] += sizes[parentOfSecond];
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    UnionFind uf(m);
    for (int i = 0; i < n; i++)
    {
        int f, t;
        cin >> f >> t;
        uf.unionVertices(f, t);
    }

    unordered_set<int> visited;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (visited.count(uf.getParent(i)) == 0)
        {
            visited.insert(uf.getParent(i));
            if (uf.sizes[uf.getParent(i)] > 1)
            {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
