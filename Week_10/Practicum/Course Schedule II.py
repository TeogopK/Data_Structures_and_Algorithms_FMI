def dfs(graph, visited, current):
    visited[current] = 1

    for neighb in graph[current]:
        if visited[neighb] == 1:
            return True
        elif visited[neighb] == 0:
            if dfs(graph, visited, neighb):
                return True

    visited[current] = 2
    return False

def topo_sort(graph, in_degree, n):
    print(in_degree)
    q = deque()
    for node in range(n):
        if in_degree[node] == 0:
            q.append(node)

    ans = []

    while q:
        node = q.pop()
        ans.append(node)
        for neighb in graph[node]:
            in_degree[neighb] -= 1
            if in_degree[neighb] == 0:
                q.append(neighb)

    return ans

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        in_degree = defaultdict(int)

        for edge in prerequisites:
            graph[edge[1]].append(edge[0])
            in_degree[edge[0]] += 1

        visited = defaultdict(int)

        for node in list(graph.keys()):
            if visited[node] == 0 and dfs(graph, visited, node):
                return []

        return topo_sort(graph, in_degree, numCourses)
        