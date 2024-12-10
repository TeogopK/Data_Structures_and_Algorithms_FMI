from collections import deque

def bfs(starting_vertex, visited, graph):
    q = deque([starting_vertex])
    visited.add(starting_vertex)

    while q:
        current = q.popleft()

        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                q.append(neighbor)

def count_areas(graph):
    count = 0
    visited = set()

    for vertex in graph:
        if vertex in visited:
            continue
        bfs(vertex, visited, graph)
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
