import heapq
from collections import defaultdict

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    priority_queue = []
    for s in start:
        priority_queue.append((0, s))
        distances[s] = 0

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances


graph = defaultdict(list)

V, E = [int(x) for x in input().split()]

for _ in range(E):
    x1, x2, w = [int(x) for x in input().split()]
    
    graph[x1].append((x2, w))
    graph[x2].append((x1, w))
    
K = int(input())
start = [int(x) for x in input().split()]

dist = dijkstra(graph, start)

Q = int(input())

for _ in range(Q):
    query = int(input())
    print(dist[query])