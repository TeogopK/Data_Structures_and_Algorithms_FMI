class Solution:
    def dfs(self, current_node, end_node, path, visited, all_paths, graph):
        for neigh in graph[current_node]:
            if neigh in visited:
                continue
            
            if neigh == end_node:
                all_paths.append(path + [end_node])
                continue

            path.append(neigh)
            visited.add(neigh)

            self.dfs(neigh, end_node, path, visited, all_paths, graph)
            path.pop()
            visited.remove(neigh)
        
        return all_paths

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        N = len(graph)

        start_node = 0
        end_node =  N - 1

        all_paths = []
        path = [start_node]
        visited = set([start_node])

        return self.dfs(start_node, end_node, path, visited, all_paths, graph)