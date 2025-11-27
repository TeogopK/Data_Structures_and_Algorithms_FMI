"""
Example [3, 4, 7, -2, 2, 1, 4, 2] and k=7

Sums [0] + [3, 7, 14, 12, 14, 15, 19, 21]
Searches [-4, *0, *7, 5, *7, 8, *12, **14]

Solutions [3, 4], [7], [7, -2, 2], [2, 1, 4], [-2, 2, 1, 4, 2], [1, 4, 2]
"""
from collections import defaultdict

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        current_sum = 0
        count = 0

        d = defaultdict(int)
        d[0] = 1

        for el in nums:
            current_sum += el
            count += d[current_sum - k]
            d[current_sum] += 1

        return count