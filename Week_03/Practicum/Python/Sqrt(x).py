class Solution:
    def mySqrt(self, x: int) -> int:
        left = 0
        right = x
        target = math.sqrt(x)
        res = -1

        while(left <= right):
            mid = left + int((right - left) / 2)
            if mid <= target:
                res = mid
                left = mid + 1
            else:
                right = mid - 1

        return res