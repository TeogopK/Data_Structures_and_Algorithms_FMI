# https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}  # number -> index
        for index, number in enumerate(nums):
            complement = target - number
            if complement in seen:
                return [seen[complement], index]

            seen[number] = index
