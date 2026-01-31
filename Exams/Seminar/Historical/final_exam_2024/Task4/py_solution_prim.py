"""
Solution idea:
    Prim's algorithm finds only one minimal spanning tree
        in a disconnected graph.
    Repeatedly executing Prim's algorithm for each connected component
        should solve the task.
    Prim's iteration must end when all nodes that were found in the construction
        of the MST are connected with each other.
    The same termination count will be used to determine which
        MST to include in the sum
"""
from heapq import heappush, heappop

def prim(start, visited, graph):
    pq = [(0, start)]
    mst_weight = 0
    
    newly_seen = set([start]) # keeps track of the newly added vertices
    reached = 0
    
    while reached != len(newly_seen):
        current_weight, current_vertex = heappop(pq)
        
        if current_vertex in visited:
            continue
        
        reached += 1
        
        visited.add(current_vertex)
        mst_weight += current_weight
        
        for neighb, weight in graph[current_vertex]:
            if neighb in visited:
                continue
            
            newly_seen.add(neighb)
            heappush(pq, (weight, neighb))
    
    return mst_weight, reached

def through_all(K, graph):
    visited = set()
    total_weight = 0
    
    for vertex in graph:
        if vertex in visited:
            continue
        
        tree_weight, vertices_added = prim(vertex, visited, graph)
        
        if vertices_added % K == 0:
            total_weight += tree_weight 
    
    return total_weight

T = int(input())

for _ in range(T):
    V, E, K = map(int, input().split())
    
    graph = {v: set() for v in range(V)}
    for _ in range(E):
        x, y, w = map(int, input().split())
        graph[x].add((y, w))
        graph[y].add((x, w))

    total = through_all(K, graph)
    print(total)
