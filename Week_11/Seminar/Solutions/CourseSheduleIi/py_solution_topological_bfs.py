from collections import deque

class Solution:

    def topological_bfs(self, graph):
        in_degree = {v: 0 for v in graph.keys()}

        for vertex in graph:
            for child in graph[vertex]:
                in_degree[child] += 1

        order = [v for v in graph.keys() if in_degree[v] == 0]
        
        q = deque(order)
        visited = set(order)

        while q:
            current = q.popleft()

            for neighbor in graph[current]:
                if neighbor not in visited:
                    in_degree[neighbor] -= 1
                
                if in_degree[neighbor] == 0:
                    visited.add(neighbor)
                    q.append(neighbor)
                    order.append(neighbor)
        
        return order

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {v: set() for v in range(numCourses)}

        for advanced, beginner in prerequisites:
            graph[beginner].add(advanced)

        order = self.topological_bfs(graph)

        return order if len(order) == numCourses else []
        