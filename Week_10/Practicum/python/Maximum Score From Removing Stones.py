class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        heap = [-a,-b,-c]
        heapq.heapify(heap)

        ans =0
        while len(heap) >= 2:
            p1 = heapq.heappop(heap)
            p2 = heapq.heappop(heap)

            if p1 + 1 !=0:
                heapq.heappush(heap, p1+1)

            if p2 + 1 != 0:
                heapq.heappush(heap, p2+1)
            
            ans += 1
        
        return ans