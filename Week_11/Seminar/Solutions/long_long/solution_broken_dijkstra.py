"""Modified 'Dijkstra' solution (Bellman-Ford)"""
from heapq import heappop, heappush

def dijkstra(S, F, V, graph):
    distances = [1] * (V + 1)
    distances[S] = 0
    
    pq = [(0, S)]
    
    while pq:
        total_weight, current = heappop(pq)
        
        for neighb, added_weight in graph[current]:
            new_weight = total_weight + added_weight
            
            if new_weight < distances[neighb]:
                distances[neighb] = new_weight
                heappush(pq, (new_weight, neighb))
    
    return -distances[F]
    
N, M, S, F = map(int, input().split())
graph = {v: set() for v in range(1, N + 1)}

for _ in range(M):
    x, y, w = map(int, input().split())
    w = -w
    graph[x].add((y, w))

distance = dijkstra(S, F, N, graph)
print(distance)