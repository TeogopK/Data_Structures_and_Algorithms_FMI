# The expected (simplest) solution
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        from collections import defaultdict

        d = defaultdict(int)
        for x in nums:
            d[x] += 1

        nums.sort(key=lambda x: (d[x], -x))
        return nums
