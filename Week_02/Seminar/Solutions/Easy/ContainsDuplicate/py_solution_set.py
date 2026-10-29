# https://leetcode.com/problems/contains-duplicate/
class Solution:
    def containsDuplicate(self, nums):
        return len(nums) != len(set(nums))  # Set is not discussed yet.
