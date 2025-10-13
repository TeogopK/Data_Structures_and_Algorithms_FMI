# Sorts the list by criteria != 0. (Note that sort() is stable.)


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort(key=lambda x: not x)
