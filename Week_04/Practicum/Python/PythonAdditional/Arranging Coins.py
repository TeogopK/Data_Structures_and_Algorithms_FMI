def f(rows, coins):
    return coins >= int((1 + rows) * rows / 2)

def bs(left, right, n):
    ans = 0
    while left <= right:
        mid = (left + right) // 2
        if f(mid, n):
            ans = mid
            left = mid + 1
        else:
            right = mid - 1

    return ans

class Solution:
    def arrangeCoins(self, n: int) -> int:
        return bs(0, n, n)