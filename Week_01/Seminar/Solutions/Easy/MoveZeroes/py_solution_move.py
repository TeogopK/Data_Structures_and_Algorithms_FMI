# Moves each nonzero number in the beginning of the list.
# Adds the required zeroes in the end.


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0

        for num in nums:
            if num:
                nums[i] = num
                i += 1

        while i < len(nums):
            nums[i] = 0
            i += 1
