INF = float('-infinity')

def bellman_ford(start, V, graph):
    distances = [INF] * (V + 1)
    distances[start] = 0
    
    for _ in range(V - 1):
        for v in range(1, V + 1):
            for child, weight in graph[v]:
                distances[child] = max(distances[child], distances[v] + weight)
    
    return distances

    
N, M, S, F = map(int, input().split())
graph = {v: set() for v in range(1, N + 1)}

for _ in range(M):
    x, y, w = map(int, input().split())
    graph[x].add((y, w))

distances = bellman_ford(S, N, graph)
answer = distances[F] if distances[F] != INF else -1
print(answer)