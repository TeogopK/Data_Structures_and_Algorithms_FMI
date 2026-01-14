import sys
sys.setrecursionlimit(100_000)

def find(x, parents):
    if parents[x] == x:
        return x

    return find(parents[x], parents)

def union(x, y, parents):
    x_root = find(x, parents)
    y_root = find(y, parents)

    parents[x_root] = y_root

def kruskal(V, edges):
    edges.sort(key=lambda x: x[2])
    parents = [i for i in range(V + 1)]
    mst_weight = 0

    for x, y, w in edges:
        if find(x, parents) != find(y, parents):
            mst_weight += w
            union(x, y, parents)

    return mst_weight
    
N, M = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(M)]
    
mst_weight = kruskal(N, edges)
print(mst_weight)