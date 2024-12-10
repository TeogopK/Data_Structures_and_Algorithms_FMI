"""
Solution using coloring with 0, 1, 2.

Nodes that are in the current dfs stack are marked with 1.
When they are exiting the stack - marked with 2.

When we visit a node that is already checked we skipped it.
When we visit a node that is already in the stack (state 1) there is a cycle.

States are:
0 - not visited
1 - in progress
2 - already checked
"""
from collections import defaultdict

def dfs(current, graph, visited):
    if visited[current] == 1:
        return True
    
    if visited[current] == 2:
        return False
    
    visited[current] = 1
    
    for neighb in graph[current]:
        if dfs(neighb, graph, visited):
            return True
        
    visited[current] = 2


def solve():
    N, M = map(int, input().split())
    graph = defaultdict(list)
        
    for _ in range(M):
        x, y, _ = map(int, input().split())
        graph[x].append(y)
    
    visited = [0] * (N + 1)
    
    for node in list(graph.keys()):
        if visited[node] == 2:
            continue
            
        if dfs(node, graph, visited):
            return 'true'
    
    return 'false'
    
    
Q = int(input())
for _ in range(Q):
    print(solve(), end=' ')
    