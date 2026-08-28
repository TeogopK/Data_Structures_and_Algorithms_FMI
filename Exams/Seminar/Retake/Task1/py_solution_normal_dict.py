class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        d = {}
        for x in nums:
            if x in d: # Can be done with default dict
                d[x] += 1
            else:
                d[x] = 0

        nums.sort(key=lambda x: (d[x], -x))
        return nums
