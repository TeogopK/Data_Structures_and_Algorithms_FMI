class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)

        # First transposes the matrix
        for i in range(N):
            for j in range(i + 1, N):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Then reverses each row
        for i in range(N):
            matrix[i].reverse()
            # matrix[i] = matrix[i][::-1] # Creates a new list!
