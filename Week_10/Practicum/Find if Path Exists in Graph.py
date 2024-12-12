def dfs(graph, visited, current, target):
    if current not in visited or visited[current]:
        return

    if current == target:
        return True

    visited[current] = True

    for node in graph[current]:
        if dfs(graph, visited, node, target):
            return True

    return False


class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True

        graph = defaultdict(list)
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        visited = {node: False for node in graph.keys()}

        return dfs(graph, visited, source, destination)