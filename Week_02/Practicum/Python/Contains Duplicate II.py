from collections import defaultdict
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        nums = [(num, i) for i, num in enumerate(nums)]

        nums.sort()

        for i in range(len(nums) - 1):
            if nums[i][0] == nums[i + 1][0] and nums[i + 1][1] - nums[i][1] <= k:
                return True

        return False