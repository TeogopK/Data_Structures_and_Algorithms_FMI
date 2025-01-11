class Solution {

struct DisjointSet {
    vector<int> parents;

    DisjointSet(int n) {
        for (int i =0; i < n; i++) {
            parents.push_back(i);
        }
    }

    int find(int v) {
        if (v == parents[v])
            return v;
        return parents[v] = find(parents[v]);
    }

    void unite(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU == parentV) {
            return;
        }

        parents[parentU] = parentV;
    }
};

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);

        for (auto& edge : edges) {
            ds.unite(edge[0], edge[1]);
        }

        return ds.find(source) == ds.find(destination);
    }
};