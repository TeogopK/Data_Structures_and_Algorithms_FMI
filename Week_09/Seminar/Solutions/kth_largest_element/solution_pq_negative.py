from queue import PriorityQueue

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq = PriorityQueue()
        for num in nums:
            pq.put(-num)

        for _ in range(k-1):
            pq.get()

        return -pq.queue[0]
