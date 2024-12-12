def dfs(graph, visited, current, current_component):
    if visited[current]:
        return

    current_component.append(current)

    visited[current] = True

    for node in graph[current]:
        dfs(graph, visited, node, current_component)

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        visited = [False for node in range(n)]

        connected_components = []

        for node in range(n):
            if not visited[node]:
                current_component = []
                dfs(graph, visited, node, current_component)
                connected_components.append(current_component)

        count = 0

        for component in connected_components:
            complete = True
            for node in component:
                if len(graph[node]) != len(component) - 1:
                    complete = False
                    break
            count = count + 1 if complete else count

        return count
