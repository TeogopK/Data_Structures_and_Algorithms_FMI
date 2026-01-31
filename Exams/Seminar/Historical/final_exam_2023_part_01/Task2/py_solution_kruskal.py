import sys
from collections import defaultdict

sys.setrecursionlimit(1_000_000)

def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents, rank):
    x_root = find(x, parents)
    y_root = find(y, parents)

    parents[x_root] = y_root

def solve(K, V, edges):
    rank = [0] * V
    parents = [v for v in range(V)]

    for x, y in edges:
        union(x, y, parents, rank)

    groups = defaultdict(int)
    for v in range(V):
        parent = find(v, parents)
        groups[parent] += 1

    total = sum(1 for group in groups.values() if group % K == 0)
    
    print(total)
    
N, E, K = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(E)]

solve(K, N, edges)