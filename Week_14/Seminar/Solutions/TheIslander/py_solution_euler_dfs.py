def dfs(current, visited, graph):
    for neighbor in graph[current]:
        if neighbor not in visited:
            visited.add(neighbor) 
            dfs(neighbor, visited, graph)
            
            
def is_connected(V, graph):
    start_vertex = 1
    visited = set([start_vertex])
    
    dfs(start_vertex, visited, graph)
    
    return len(visited) >= V


def check_euler(V, graph):
    degrees = [0] * (V + 1)
    
    for v in graph:
        degrees[v] = len(graph[v])
        
    count_odd = sum(1 if degree % 2 == 1 else 0 for degree in degrees)
    
    if not is_connected(V, graph):
        return 'none'
    
    if count_odd == 0:
        return 'ecycle'
    
    if count_odd == 2:
        return 'epath'
    
    return 'none'
    

def solve():
    N, M = map(int, input().split())
    graph = {v: [] for v in range(N + 1)}
    
    for _ in range(M):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
        
    result = check_euler(N, graph)
    
    return result

Q = int(input())
for _ in range(Q):
    print(solve())