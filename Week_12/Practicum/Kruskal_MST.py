import sys
sys.setrecursionlimit(100_000)

def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents):
    x_root = find(x, parents)
    y_root = find(y, parents)

    if x_root != y_root:
        parents[x_root] = y_root
        return 1
        
    return 0

V, E = [int(x) for x in input().split()]

parents = [i for i in range(V)]
ans = 0

edges = []

for i in range(E):
    x1, x2, w = [int(x) for x in input().split()]
    edges.append((x1, x2, w))

edges.sort(key=lambda x: x[2])

for x1, x2, w in edges:
    if union(x1 - 1, x2 - 1, parents):
        ans += w
        
print(ans)
