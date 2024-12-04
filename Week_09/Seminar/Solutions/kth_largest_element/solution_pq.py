from queue import PriorityQueue

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq = PriorityQueue()

        for num in nums:
            pq.put(num)

        p = len(nums) - k

        for _ in range(p):
            pq.get()

        return pq.queue[0]
