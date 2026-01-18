from heapq import heappop, heappush
from collections import defaultdict

INF = float("infinity")


def dijkstra(start, V, graph):
    distances = [INF] * V
    # to store predecessors
    predecessors = [-1] * V
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
                # update predecessor
                predecessors[neighb] = current
                heappush(pq, (new_weight, neighb))

    return distances, predecessors


def reconstruct_path(start, end, predecessors):
    path = []
    at = end

    while at != -1:
        path.append(at)
        at = predecessors[at]

    path.reverse()
    return path if path[0] == start else [-1]  # return empty path if there is no path from start to end


V, E, start, end = [int(x) for x in input().split()]
graph = defaultdict(list)

for _ in range(E):
    u, v, w = [int(x) for x in input().split()]
    graph[u].append((v, w))
    graph[v].append((u, w))

dist, pred = dijkstra(start, V + 1, graph)

print(*reconstruct_path(start, end, pred))
