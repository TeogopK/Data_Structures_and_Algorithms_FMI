# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def binary_search(self, left, right):
        while left <= right:
            mid = (left + right) // 2
        
            if isBadVersion(mid):
                right = mid - 1
            else:
                left = mid + 1

        return left
        
    def firstBadVersion(self, n: int) -> int:
        return self.binary_search(0, n)