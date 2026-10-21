"""Solution using the implemented binary search for leftmost index"""

import bisect


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return bisect.bisect_left(nums, target)
