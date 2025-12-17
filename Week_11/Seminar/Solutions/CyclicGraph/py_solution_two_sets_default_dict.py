"""
Solution representing the graph as defaultdict.

IMPORTANT!

Note that using just 'node in graph' results in
'RuntimeError: dictionary changed size during iteration'
due to the default dictionary creating key for each vertex 
that does not have any paths starting from it.

Another workaround is defining the graph as
'graph = {node: [] for node in range(1, N + 1)}'.
"""
from collections import defaultdict

def dfs_has_cycle(current, in_progress, visited, graph):
    in_progress.add(current)

    for neighbor in graph[current]: # Can create a new key causing an exception if there is no copy!
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

    for vertex in list(graph.keys()): # Creates a copy.
        if vertex in visited:
            continue
            
        visited.add(vertex)
        in_progress = set()
        
        if dfs_has_cycle(vertex, in_progress, visited, graph):
            return True

    return False

def solve():
    N, M = map(int, input().split())
    graph = defaultdict(list)
        
    for _ in range(M):
        x, y, _ = map(int, input().split())
        graph[x].append(y) # Not adding every vertex.
    
    return 'true' if check_has_cycle(graph) else 'false'
    
    
Q = int(input())
for _ in range(Q):
    print(solve(), end=' ')
    