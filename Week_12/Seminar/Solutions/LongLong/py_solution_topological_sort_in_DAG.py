def topological_dfs(u, visited, stack, graph):
    visited.add(u)
    for v, _ in graph[u]:
        if v not in visited:
            topological_dfs(v, visited, stack, graph)
    stack.append(u)


def topological_sort(graph):
    visited = set()
    stack = []
    for u in graph:
        if u not in visited:
            topological_dfs(u, visited, stack, graph)
    stack.reverse()
    return stack


def longest_path_dag(S, F, V, graph):
    NEG_INF = -float("infinity")
    dist = [NEG_INF] * (V + 1)
    dist[S] = 0

    topo = topological_sort(graph)

    for u in topo:
        if dist[u] == NEG_INF:
            continue
        for v, w in graph[u]:
            if dist[u] + w > dist[v]:
                dist[v] = dist[u] + w

    return -1 if dist[F] == NEG_INF else dist[F]


N, M, S, F = map(int, input().split())
graph = {i: [] for i in range(1, N + 1)}

for _ in range(M):
    x, y, w = map(int, input().split())
    graph[x].append((y, w))

print(longest_path_dag(S, F, N, graph))
