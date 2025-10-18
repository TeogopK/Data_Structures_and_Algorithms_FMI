class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        v = []
        i = 0
        while i + n // 3 < n:
            if nums[i] == nums[i + n // 3] and nums[i] not in v:
                v.append(nums[i])
            i += 1

        return v