class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xxor = 0
        for num in nums:
            xxor ^= num

        return xxor
