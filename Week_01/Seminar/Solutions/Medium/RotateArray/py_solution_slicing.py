class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)  # K can be > than len(nums)
        nums[:] = nums[-k:] + nums[:-k]
