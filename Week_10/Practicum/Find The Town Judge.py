class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        in_degree = defaultdict(int)
        out_degree = defaultdict(int)

        for edge in trust:
            out_degree[edge[0]] += 1
            in_degree[edge[1]] += 1

        
        for i in range(1, n + 1):
            if in_degree[i] == n - 1 and out_degree[i] == 0:
                return i

        return -1