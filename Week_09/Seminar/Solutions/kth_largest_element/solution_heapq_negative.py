import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        max_heap = [-num for num in nums]
        heapq.heapify(max_heap)

        for _ in range(k-1):
            heapq.heappop(max_heap)

        return -max_heap[0]
