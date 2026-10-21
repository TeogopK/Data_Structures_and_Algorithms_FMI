"""Note that binary search finds the index
where the element must be inserted if not present"""


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        answ = r + 1  # for bigger numbers than maximum

        while l <= r:
            m = (l + r) // 2

            if target <= nums[m]:
                r = m - 1
                answ = m
            else:
                l = m + 1

        return answ
