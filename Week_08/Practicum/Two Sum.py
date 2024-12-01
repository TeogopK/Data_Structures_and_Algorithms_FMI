class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()

        for i, num in enumerate(nums):
            d[num] = i

        for i, num in enumerate(nums):
            if target - num in d.keys() and i != d[target - num]:
                return [i, d[target - num]]
