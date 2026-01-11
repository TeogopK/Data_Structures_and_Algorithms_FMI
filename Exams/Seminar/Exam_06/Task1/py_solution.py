from heapq import heappop, heappush

INF = float("inf")


def dijkstra(start, V, graph):
    distances = [INF] * V
    distances[start] = 0

    visited = set()

    pq = [(0, start)]

    while pq:
        total_weight, current = heappop(pq)

        t = times[current]
        total_weight = ((total_weight // t) + (1 * bool(total_weight % t))) * t

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

    return distances


V, E, start, end = [int(x) for x in input().split()]

times = [int(x) for x in input().split()]

graph = {v: [] for v in range(V)}

for _ in range(E):
    u1, u2, w = [int(x) for x in input().split()]
    graph[u1].append((u2, w))

dist = dijkstra(start, V, graph)

print(-1 if dist[end] == INF else dist[end])
