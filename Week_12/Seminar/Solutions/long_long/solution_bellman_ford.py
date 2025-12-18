"""
The main idea is that finding the longest path can not be obtained
by using Dijkstra with reversed (only negative) weights.

This is because a vertex with direct edge with weight 4 (-4),
will be marked as visited, although a path 1 + 2 + 5 > 4 exists.
Even in reverse -4 > -1 + (-2) + (-3).

This means that we must use Bellman-Ford.
It will find the shortest path -5 < -4 even though there are negative weights.

Node that the graph does not have cycles (DAG).
"""
INF = float('infinity')

def bellman_ford(start, V, E, graph):
    distances = [INF] * (V + 1)
    distances[start] = 0
    
    for _ in range(V - 1):
        for x, y, w in graph: # O(E)
            distances[y] = min(distances[y], distances[x] - w)
    
    return distances
    
N, M, S, F = map(int, input().split())
graph = [tuple(map(int, input().split())) for _ in range(M)] # List of edges

distances = bellman_ford(S, N, M, graph)
answer = -distances[F] if distances[F] != INF else -1
print(answer)
