def dfs(isConnected, visited, current):
    if current not in visited or visited[current]:
        return

    visited[current] = True

    for node in range(len(isConnected[current])):
        if isConnected[current][node]:
            dfs(isConnected, visited, node)


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = {node: False for node in range(len(isConnected))}

        total = 0

        for node in range(len(isConnected)):
            if not visited[node]:
                total += 1
                dfs(isConnected, visited, node)

        return total