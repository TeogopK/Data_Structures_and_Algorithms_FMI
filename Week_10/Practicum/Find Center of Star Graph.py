class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        in_degree = defaultdict(int)

        for edge in edges:
            in_degree[edge[0]] += 1
            in_degree[edge[1]] += 1

            if in_degree[edge[0]] > 1:
                return edge[0]
            if in_degree[edge[1]] > 1:
                return edge[1]