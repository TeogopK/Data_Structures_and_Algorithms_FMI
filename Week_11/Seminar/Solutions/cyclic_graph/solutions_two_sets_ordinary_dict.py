"""Solution using ordinary dictionary to represent the graph."""

def dfs_has_cycle(current, in_progress, visited, graph):
    in_progress.add(current)

    for neighbor in graph[current]:
        if neighbor in in_progress:
            return True
        
        if neighbor not in visited:
            visited.add(neighbor)
            if dfs_has_cycle(neighbor, in_progress, visited, graph):
                return True
    
    in_progress.remove(current)
    return False

def check_has_cycle(graph):
    visited = set()

    for vertex in graph:
        if vertex in visited:
            continue
            
        visited.add(vertex)
        in_progress = set()
        
        if dfs_has_cycle(vertex, in_progress, visited, graph):
            return True

    return False

def solve():
    N, M = map(int, input().split())
    graph = {node: [] for node in range(1, N + 1)}
        
    for _ in range(M):
        x, y, _ = map(int, input().split())
        graph[x].append(y)
    
    return 'true' if check_has_cycle(graph) else 'false'
    
    
Q = int(input())
for _ in range(Q):
    print(solve(), end=' ')
    