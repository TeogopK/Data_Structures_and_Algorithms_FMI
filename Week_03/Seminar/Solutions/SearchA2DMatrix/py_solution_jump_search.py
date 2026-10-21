class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        N = len(matrix)

        i = 0
        while i < N and target > matrix[i][-1]:
            i += 1

        if i == N:
            return False

        return target in matrix[i]
