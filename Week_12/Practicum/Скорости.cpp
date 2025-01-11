#include <bits/stdc++.h>

int root[1001] {}, N, M, f, t, s, minS = 0, maxS = INT_MAX;

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

void yunion(int x, int y) {
    root[find(x)] = find(y);
}

struct edge {
    int f, t, s;
    
    bool operator<(const edge &other) {
        return s < other.s;
    }
} edges[(int)1e5] {};

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> f >> t >> s;
        edges[i] = {f, t, s };
    }
    
    std::sort(edges, edges + M);
    int lim = M - N + 1;
    for (int i = 0; i <= lim; ++i) {
        std::iota(root, root + N + 1, 0);
        int count = 0;
        int currMax = 0;
        for (int j = i; j < M; ++j) {
            if (find(edges[j].f) != find(edges[j].t)) {
                currMax = std::max(currMax, edges[j].s);
                yunion(edges[j].f, edges[j].t);
                count++;
            }
            if (count == N - 1) break;
        }
        if (count == N - 1 && currMax - edges[i].s < maxS - minS) {
            minS = edges[i].s;
            maxS = currMax;
        }
    }
    
    std::cout << minS << ' ' << maxS;
    return 0;
}

