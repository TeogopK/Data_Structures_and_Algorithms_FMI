#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


struct UnionFind {
    int components;
    vector<int> parents;
    vector<int> sizes;
    
    UnionFind(int n) : parents(n), sizes(n,1), components(n) {
        iota(parents.begin(), parents.end(), 0);
    }
    
    int find(int node) {
        if(parents[node] == node) {
            return node;
        }
        
        return parents[node] = find(parents[node]);
    }
    
    void unite(int a, int b) {
        int ap = find(a);
        int bp = find(b);
        
        if(ap == bp) {
            return;
        }
        
        if(sizes[ap] < sizes[bp]) {
            swap(ap, bp);
        }
        
        sizes[ap] += sizes[bp];
        parents[bp] = ap;
        components--;
    }
    
    int divisibleByK(int k) {
        int count = 0;
        for(int i = 0; i < parents.size(); i++) {
            if(i == find(i) && sizes[i] % k == 0) {
                count++;
            }
        }
        
        return count;
    }
    
    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, e, k;
    cin >> n >> e >> k;
    
    UnionFind uf(n);
    
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }
    
    cout << uf.divisibleByK(k);
    
    return 0;
}
