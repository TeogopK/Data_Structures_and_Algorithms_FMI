class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        N = len(nums)
        all_pairs = N * (N - 1) // 2
        good_pairs = 0
        
        d = {}

        for i, num in enumerate(nums):
            target = num - i
            if target in d:
                good_pairs += d[target]
                d[target] += 1
            else:
                d[target] = 1

        return all_pairs - good_pairs
