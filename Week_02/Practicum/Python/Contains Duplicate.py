class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort() # nlogn

        for i in range(len(nums) - 1): # n
            if nums[i] == nums[i + 1]:
                return True

        return False