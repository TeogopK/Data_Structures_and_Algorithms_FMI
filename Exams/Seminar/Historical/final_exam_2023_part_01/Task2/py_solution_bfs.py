from collections import deque

def bfs(starting_vertex, visited, graph):
    q = deque([starting_vertex])
    visited.add(starting_vertex)
    
    total_nodes = 1

    while q:
        current = q.popleft()

        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                q.append(neighbor)
                total_nodes += 1
                
    return total_nodes            

def solve(graph):
    count = 0
    visited = set()

    for vertex in graph:
        if vertex in visited:
            continue
        visited.add(vertex)
        
        total_nodes = bfs(vertex, visited, graph)
        if total_nodes % K == 0:
            count += 1

    return count
    
N, E, K = map(int, input().split())
graph = {v: set() for v in range(N)}

for _ in range(E):
    x, y = map(int, input().split())
    graph[x].add(y)
    graph[y].add(x)
    
print(solve(graph))