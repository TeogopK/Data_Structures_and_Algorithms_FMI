from collections import defaultdict
import heapq

def dijkstra(graph, V):
    dist = {node: 2**63 for node in range(1, V + 1)}
    dist[1] = 0
    ways = {node: 1 for node in range(1, V + 1)}

    pq = [(0, 1)]

    while len(pq):
        node_dist, node = heapq.heappop(pq)
        
        if node_dist > dist[node]:
            continue

        for neighb, neighb_dist in graph[node]:
            
            if neighb_dist + node_dist < dist[neighb]:
                dist[neighb] = neighb_dist + node_dist
                heapq.heappush(pq, (dist[neighb], neighb))
                ways[neighb] = ways[node]
                
            elif neighb_dist + node_dist == dist[neighb]:
                ways[neighb] += ways[node]
                
    if V not in dist or dist[V] == 2**63:
        return -1, 0
    return dist[V], ways[V] % (10**9 + 7)

graph = defaultdict(list)

V, E = [int(x) for x in input().split()]

for _ in range(E):
    x1, x2, w = [int(x) for x in input().split()]
    graph[x1].append((x2, w))

print(*dijkstra(graph, V))
