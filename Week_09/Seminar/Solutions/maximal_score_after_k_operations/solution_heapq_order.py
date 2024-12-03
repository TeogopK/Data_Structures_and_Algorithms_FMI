"""Defining a new comparison method"""
import heapq

class MaxElement():
    def __init__(self, value):
        self.value = value
    
    def __lt__(self, other):
        return self.value > other.value

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        max_heap = [MaxElement(num) for num in nums]
        heapq.heapify(max_heap)

        score = 0
        for _ in range(k):
            num = heapq.heappop(max_heap).value
            score += num

            heapq.heappush(max_heap, MaxElement(ceil(num / 3)))

        return score