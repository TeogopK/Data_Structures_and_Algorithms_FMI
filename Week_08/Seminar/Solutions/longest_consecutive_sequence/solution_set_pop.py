class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        max_length = 0

        while s:
            low = high = s.pop()
            
            while low - 1 in s or high + 1 in s:
                if low - 1 in s:
                    s.remove(low - 1)
                    low -= 1
                
                if high + 1 in s:
                    s.remove(high + 1)
                    high += 1

            max_length = max(high - low + 1, max_length)

        return max_length