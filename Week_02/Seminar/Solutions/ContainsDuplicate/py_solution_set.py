class Solution:
    def containsDuplicate(self, nums):
        return len(nums) != len(set(nums))  # Set is not discussed yet.
