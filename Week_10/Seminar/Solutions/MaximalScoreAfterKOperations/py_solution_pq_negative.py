"""Keep the largest in Max Heap by adding the numbers as negative"""
from queue import PriorityQueue

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = PriorityQueue()
        for num in nums:
            pq.put(-num)

        score = 0
        for _ in range(k):
            num = -pq.get()
            score += num

            pq.put(-ceil(num / 3))

        return score