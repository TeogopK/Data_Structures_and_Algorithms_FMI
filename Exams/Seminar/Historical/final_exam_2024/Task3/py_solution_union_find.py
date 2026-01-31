"""
Task: Find the number of components in the graph that are not trees.

Solution idea:
    Start constructing the graph by adding each edge and connecting the components.
    If the two components have the same parent and there was no cycle in either component yet,
        mark the components as having a cycle and increase the counter of cycles.
    If the two components have different parents but one of them has a cycle,
        do not increment the counter, mark both as having a cycle,
    If the two components have different parents but the two of them had a cycle,
        decrease the counter.
"""

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

    parents[x_root] = y_root

def solve(V, edges):
    parents = [i for i in range(V)]
    cycles = [False] * V
    total = 0

    for x, y in edges:
        px = find(x, parents)
        py = find(y, parents)
        
        if px != py:
            if cycles[px] and cycles[py]:
                total -= 1
            if cycles[px] or cycles[py]:
                cycles[px] = cycles[py] = True
            union(x, y, parents)
        elif not cycles[px]:
            total += 1
            cycles[px] = True
        
    return total

T = int(input())
for _ in range(T):
    V, E = map(int, input().split())

    edges = set(tuple(map(int, input().split())) for _ in range(E))

    total = solve(V, edges)
    print(total)
