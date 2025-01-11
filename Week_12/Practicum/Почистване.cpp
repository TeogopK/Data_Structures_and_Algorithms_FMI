#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct DisjointSet {
    vector<int> parents;

    DisjointSet(int n) {
        for (int i =0; i <= n; i++) {
            parents.push_back(i);
        }
    }

    int find(int v) {
        if (v == parents[v])
            return v;
        return parents[v] = find(parents[v]);
    }

    bool unite(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU == parentV) {
            return false;
        }

        parents[parentU] = parentV;
        return true;
    }
};

int main() {
    int v, edges, a, b;
    cin >> v >> edges;
    if (v == 1) {
        cout << 0;
        return 0;
    }
    DisjointSet ds(v);
    
    int count = 0;
    
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        
        if (ds.unite(a, b)) {
            count++;
            
            if (count == v - 1) {
                cout << i + 1;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
