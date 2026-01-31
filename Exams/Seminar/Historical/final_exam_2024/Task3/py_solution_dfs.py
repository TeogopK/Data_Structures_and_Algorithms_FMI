"""
Task: Find the number of components in the graph that are not trees.

Solution idea:
    Create a DFS traversal. 
    For each node check if any of its neighbors, except the parent one,
        are already visited.
    If there is such neighbor - the component is not a tree (there is a "cycle").
    Continue the traversal of the component to mark all nodes as visited.
        This guarantees the same component will not be checked multiple times.
"""

import sys
sys.setrecursionlimit(100_000)

def dfs(current, previous, visited, graph):
    has_cycle = False
    visited.add(current) 
    
    for neighbor in graph[current]:
        if neighbor == previous:
            continue
            
        if neighbor in visited:
            has_cycle = True
            continue
        
        has_cycle = dfs(neighbor, current, visited, graph) | has_cycle
        
    return has_cycle
          

def solve(graph):
    visited = set()
    total = 0
    
    for v in graph:
        if v in visited:
            continue
        
        if dfs(v, -1, visited, graph):
            total += 1
    return total
    

T = int(input())
for _ in range(T):
    V, E = map(int, input().split())

    graph = {v: set() for v in range(V)}
    
    for _ in range(E):
        x, y = map(int, input().split())
        graph[x].add(y)
        graph[y].add(x)
        
    answer = solve(graph)
    print(answer)
