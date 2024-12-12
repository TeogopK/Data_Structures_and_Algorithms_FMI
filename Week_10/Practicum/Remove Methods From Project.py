def dfs(graph, visited, current, suspicious):
    if visited[current]:
        return

    suspicious.add(current)

    visited[current] = True

    for node in graph[current]:
        dfs(graph, visited, node, suspicious)

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]
        for edge in invocations:
            graph[edge[0]].append(edge[1])

        visited = [False for node in range(n)]

        suspicious = set()
        dfs(graph, visited, k, suspicious)

        non_suspicious = list(set(range(n)) - suspicious)

        non_suspicious_invocations = []
        for non_suspicious_node in non_suspicious:
            non_suspicious_invocations.extend(graph[non_suspicious_node])

        non_suspicious_invocations = set(non_suspicious_invocations)

        return list(non_suspicious) if len(non_suspicious_invocations.intersection(suspicious)) == 0 else list(range(n))