class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        left, right = 0, len(matrix) - 1

        # Use binary search to find the row
        while left <= right:
            mid = (left + right) // 2

            row = matrix[mid]

            if row[0] > target:
                right = mid - 1
            elif row[len(row) - 1] < target:
                left = mid + 1

            else:
                left = mid
                break

        # left will always be our answer and >= 0. It can be out of bounds though
        if left > len(matrix) - 1:
            return False


        # Use binary search to find the column
        idx = bisect.bisect_left(matrix[left], target)

        if idx > len(matrix[left]) - 1 or matrix[left][idx] != target:
            return False

        return True