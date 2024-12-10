"""Solution using DFS with stack."""

def dfs_stack(starting_vertex, visited, graph):
    stack = [starting_vertex]
    visited.add(starting_vertex)

    while stack:
        current = stack.pop()

        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                stack.append(neighbor)

def count_areas(graph):
    count = 0
    visited = set()

    for vertex in graph:
        if vertex in visited:
            continue
        dfs_stack(vertex, visited, graph)
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
        
    