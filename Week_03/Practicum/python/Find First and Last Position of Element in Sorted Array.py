import bisect

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return -1, -1

        idx1, idx2 = bisect.bisect_left(nums, target), bisect.bisect_right(nums, target) - 1
        if idx1 == len(nums) or nums[idx1] != target:
            return -1, -1

        return idx1, idx2