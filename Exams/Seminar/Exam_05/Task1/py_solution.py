from collections import defaultdict
import sys

sys.setrecursionlimit(int(1e8))


def dfs(current, visited, graph, results, unique_component):
    for neighbor in graph[current]:
        results[unique_component] += 1
        if neighbor not in visited:
            visited.add(neighbor)
            dfs(neighbor, visited, graph, results, unique_component)


def count_edges_in_areas(graph):
    unique_component = 0
    visited = set()
    results = defaultdict(int)

    for vertex in graph:
        if vertex in visited:
            continue
        visited.add(vertex)
        results[unique_component] = 0  # Lonely

        dfs(vertex, visited, graph, results, unique_component)
        results[unique_component] //= 2

        unique_component += 1

    return results


N, T = map(int, input().split())
graph = {v: set() for v in range(N)}

for _ in range(T):
    x, y = map(int, input().split())

    graph[x].add(y)
    graph[y].add(x)

results = count_edges_in_areas(graph)
sorted_counts = list(sorted(results.values()))
print(*sorted_counts)
