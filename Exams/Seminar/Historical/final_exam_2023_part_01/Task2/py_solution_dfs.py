def dfs(current, visited, graph):
    total_nodes = 1
    
    for neighbor in graph[current]:
        if neighbor not in visited:
            visited.add(neighbor)
            total_nodes += dfs(neighbor, visited, graph)

    return total_nodes

def solve(graph):
    count = 0
    visited = set()

    for vertex in graph:
        if vertex in visited:
            continue
        visited.add(vertex)
        
        total_nodes = dfs(vertex, visited, graph)
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