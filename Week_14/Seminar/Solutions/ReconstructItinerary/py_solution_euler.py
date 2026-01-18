from collections import defaultdict
from heapq import heappop, heappush

class Solution:
    def euler_path(self, current, path, edges):
        while edges[current]:
            next_vertex = heappop(edges[current])
            self.euler_path(next_vertex, path, edges)

        path.append(current)
        return reversed(path)

    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        edges = defaultdict(list)
        for start, end in tickets:
            heappush(edges[start], end)

        path = []
        return self.euler_path("JFK", path, edges)