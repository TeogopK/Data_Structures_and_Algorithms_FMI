import math
import heapq
from collections import defaultdict


def dijkstra(graph, start):
    distances = {v: math.inf for v in graph}
    prev = {v: None for v in graph}

    distances[start] = 0
    visited = set()

    heap = []
    heapq.heappush(heap, (0, start))

    while heap:
        total_cost, vertex = heapq.heappop(heap)

        if vertex in visited:
            continue

        visited.add(vertex)

        for neighbor, cost_to_neighbor in graph[vertex]:
            if neighbor in visited:
                continue

            new_cost = total_cost + cost_to_neighbor
            if new_cost < distances[neighbor]:
                distances[neighbor] = new_cost
                prev[neighbor] = vertex
                heapq.heappush(heap, (new_cost, neighbor))

    return distances, prev


def find_path(graph, vertex):
    path = []

    while vertex is not None:
        path.append(vertex)
        vertex = prev[vertex]

    path.reverse()
    return path


graph = defaultdict(list)
v, e = map(int, input().split(" "))
for _ in range(e):
    v1, v2, w = map(int, input().split(" "))
    graph[v1].append((v2, w))
    graph[v2].append((v1, w))


start, end = map(int, input().split(" "))

distances, prev = dijkstra(graph, start)
print(distances[end])
print(*find_path(graph, end))
