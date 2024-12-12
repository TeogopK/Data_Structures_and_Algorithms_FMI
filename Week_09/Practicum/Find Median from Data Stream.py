import heapq
class MedianFinder:
    
    def __init__(self):
        self.max_heap = []
        self.min_heap = []


    def addNum(self, num: int) -> None:
        # If max_heap is empty OR incoming num is lesser than top of max_heap
        if len(self.max_heap) == 0 or num < -self.max_heap[0]:
            heapq.heappush(self.max_heap, -(num))
        # max_heap is not empty AND incoming num is less than top of max_heap
        else: 
            heapq.heappush(self.min_heap, num)

        # maintaining the size difference, such that max_heap can contain at-most more than 1 element compared with min_heap
        if len(self.max_heap) - len(self.min_heap) > 1:
            heapq.heappush(self.min_heap , -heapq.heappop(self.max_heap))
        elif len(self.max_heap) < len(self.min_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
    
    def findMedian(self) -> float:
        if len(self.min_heap) == len(self.max_heap):
            return (self.min_heap[0] - self.max_heap[0]) / 2
        else:
            return -self.max_heap[0]