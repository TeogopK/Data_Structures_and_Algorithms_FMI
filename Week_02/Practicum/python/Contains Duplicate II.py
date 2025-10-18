class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        
        nums_idx = [(nums[i], i) for i in range(len(nums))]
        nums_idx.sort()

        for i in range(len(nums) - 1):
            if nums_idx[i + 1][0] == nums_idx[i][0] and nums_idx[i + 1][1] - nums_idx[i][1] <= k:
                return True

        return False