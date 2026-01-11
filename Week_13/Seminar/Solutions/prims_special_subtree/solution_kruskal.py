def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents, rank):
    x_root = find(x, parents)
    y_root = find(y, parents)

    if rank[x_root] < rank[y_root]:
        parents[x_root] = y_root
    elif rank[x_root] > rank[y_root]:
        parents[y_root] = x_root
    else:
        parents[x_root] = y_root
        rank[y_root] += 1

def kruskal(V, edges):
    edges.sort(key=lambda x: x[2])
    parents = [i for i in range(V + 1)]
    rank = [0] * (V + 1)
    mst_weight = 0

    for x, y, w in edges:
        if find(x, parents) != find(y, parents):
            mst_weight += w
            union(x, y, parents, rank)

    return mst_weight
    
N, M = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(M)]
    
start = int(input())
mst_weight = kruskal(N, edges)
print(mst_weight)