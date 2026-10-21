class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        left = 0
        right = len(matrix) - 1

        Mi = -1

        while left <= right:
            mid = left + (right - left) // 2

            if target <= matrix[mid][-1]:
                right = mid - 1
                Mi = mid
            else:
                left = mid + 1

        if Mi == -1:
            return False

        left = 0
        right = len(matrix[Mi]) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if target < matrix[Mi][mid]:
                right = mid - 1
            elif target > matrix[Mi][mid]:
                left = mid + 1
            else:
                return True

        return False
