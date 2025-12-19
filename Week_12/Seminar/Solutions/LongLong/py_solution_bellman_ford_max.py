INF = float('-infinity')

def bellman_ford(start, V, E, graph):
    distances = [INF] * (V + 1)
    distances[start] = 0
    
    for _ in range(V - 1):
        for x, y, w in graph: # O(E)
            distances[y] = max(distances[y], distances[x] + w)
    
    return distances
    
N, M, S, F = map(int, input().split())
graph = [tuple(map(int, input().split())) for _ in range(M)]

distances = bellman_ford(S, N, M, graph)
answer = distances[F] if distances[F] != INF else -1
print(answer)