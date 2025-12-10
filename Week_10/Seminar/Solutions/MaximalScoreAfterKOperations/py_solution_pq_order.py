"""Defining a new comparison method"""
from queue import PriorityQueue

class MaxElement():
    def __init__(self, value):
        self.value = value
    
    def __lt__(self, other):
        return self.value > other.value

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = PriorityQueue()
        for num in nums:
            pq.put(MaxElement(num))

        score = 0
        for _ in range(k):
            max_element = pq.get()
            score += max_element.value

            new_value = ceil(max_element.value / 3)

            pq.put(MaxElement(new_value))

        return score