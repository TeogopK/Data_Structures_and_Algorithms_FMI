# Faculty_number: 3MI0600368

import heapq


def dijstra(start, end, n, graph):
    distances = [-1] * n
    visited = set()
    pq = [(0, start)]

    distances[start] = 0
    while pq:
        curr_w, curr_v = heapq.heappop(pq)

        if curr_v in visited:
            continue

        visited.add(curr_v)

        for v, w in graph[curr_v]:
            if v in visited:
                continue

            new_w = curr_w + w
            if distances[v] == -1 or new_w < distances[v]:
                distances[v] = new_w

            heapq.heappush(pq, (distances[v], v))

    return distances[end]


n, l, h = map(int, input().split())
graph = {i: set() for i in range(n)}

for _ in range(l):
    a, b = map(int, input().split())
    graph[a].add((b, 0))
    graph[b].add((a, 0))

for _ in range(h):
    a, b = map(int, input().split())
    graph[a].add((b, 1))
    graph[b].add((a, 1))

print(dijstra(0, n - 1, n, graph))
