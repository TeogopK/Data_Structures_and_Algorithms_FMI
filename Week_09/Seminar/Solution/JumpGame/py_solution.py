class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_jump = nums[0]

        for i, num in enumerate(nums):
            if max_jump < i:
                return False
            max_jump = max(max_jump, i + num)

        return True