# генерирано с claude
from collections import defaultdict


def dfs(current, graph, visited):
    visited.add(current)

    for neighbour in graph[current]:
        if neighbour not in visited:
            dfs(neighbour, graph, visited)


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1

        graph = defaultdict(list)
        for a, b in connections:
            graph[a].append(b)
            graph[b].append(a)

        components = 0
        visited = set()

        for computer in range(n):
            if computer not in visited:
                components += 1
                dfs(computer, graph, visited)

        return components - 1
