class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        in_count = [0 for _ in range(n)]

        for edge in edges:
            in_count[edge[1]] += 1

        champions = [k for k, v in enumerate(in_count) if v == 0]

        return champions[0] if len(champions) == 1 else -1