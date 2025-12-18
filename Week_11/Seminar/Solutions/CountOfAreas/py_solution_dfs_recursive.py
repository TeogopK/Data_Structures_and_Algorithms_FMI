"""Solution using DFS with recursion."""

import sys
sys.setrecursionlimit(int(1e5))

def dfs(current, visited, graph):
    for neighbor in graph[current]:
        if neighbor not in visited:
            visited.add(neighbor)
            dfs(neighbor, visited, graph)


def count_areas(graph):
    count = 0
    visited = set()

    for vertex in graph:
        if vertex in visited:
            continue

        visited.add(vertex)
        dfs(vertex, visited, graph)
        
        count += 1

    return count

Q = int(input())

for _ in range(Q):
    N, T = map(int, input().split())
    graph = {v: set() for v in range(N)}
    
    for _ in range(T):
        x, y = map(int, input().split())
        
        graph[x].add(y)
        graph[y].add(x)
        
    print(count_areas(graph), end=' ')
