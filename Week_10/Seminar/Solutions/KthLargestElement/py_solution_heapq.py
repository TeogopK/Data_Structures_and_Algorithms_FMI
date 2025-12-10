import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        p = len(nums) - k

        for _ in range(p):
            heapq.heappop(nums)

        return nums[0]