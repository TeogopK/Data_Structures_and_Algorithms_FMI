class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        piles = [-pile for pile in piles]
        heapq.heapify(piles)

        for _ in range(k):
            largest = -heapq.heappop(piles)
            largest = largest - math.floor(largest / 2)
            heapq.heappush(piles, -largest)

        return -sum(piles)