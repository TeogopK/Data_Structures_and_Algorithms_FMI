class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0 

        nums.sort()
        max_count = count = 1

        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                continue
                
            if nums[i] + 1 == nums[i + 1]:
                count += 1
                max_count = max(count, max_count)
            else:
                count = 1
        
        return max_count
        