"""Representing the graph with set of edges due to duplicated edges."""

from heapq import heappop, heappush
INF = -1

def dijkstra(start, V, graph):
    distances = [INF] * (V + 1)
    distances[start] = 0

    visited = set()
    
    pq = [(0, start)]
    
    while pq:
        total_weight, current = heappop(pq)
        
        if current in visited:
            continue
        visited.add(current)
        
        for neighb, added_weight in graph[current]:
            if neighb in visited:
                continue
                
            new_weight = total_weight + added_weight
            
            if distances[neighb] == INF or new_weight < distances[neighb]:
                distances[neighb] = new_weight
                heappush(pq, (new_weight, neighb))
    
    distances.remove(0)
    return distances[1::]
    
Q = int(input())

for _ in range(Q):
    N, M = map(int, input().split())
    graph = {v: set() for v in range(1, N + 1)}
    
    for _ in range(M):
        x, y, w = map(int, input().split())
        graph[x].add((y, w))
        graph[y].add((x, w))
    
    start = int(input())
    distances = dijkstra(start, N, graph)
    print(*distances)
