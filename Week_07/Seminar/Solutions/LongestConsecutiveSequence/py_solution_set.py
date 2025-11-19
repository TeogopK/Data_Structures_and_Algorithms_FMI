class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        max_count = 0

        for el in nums:
            if el - 1 in s:
                continue
            
            current = el + 1
            total = 1

            while current in s:
                # s.remove(current) --> improves the speed 
                total += 1
                current += 1
            
            max_count = max(total, max_count)

        return max_count
        