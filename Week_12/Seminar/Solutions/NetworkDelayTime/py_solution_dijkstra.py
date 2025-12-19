from heapq import heappop, heappush

class Solution:
    def dijkstra(self, start, V, graph):
        distances = [-1] * (V + 1)
        distances[start] = 0

        visited = set()
        
        pq = [(0, start)]
        
        while pq:
            total_weight, current = heappop(pq)
            
            if current in visited:
                continue
            visited.add(current)
            
            for neighb, added_weight in graph[current]:
                if neighb in visited:
                    continue
                    
                new_weight = total_weight + added_weight
                
                if distances[neighb] == -1 or new_weight < distances[neighb]:
                    distances[neighb] = new_weight
                    heappush(pq, (new_weight, neighb))
        
        return distances[1::]

    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = {v: set() for v in range(1, n + 1)}
        for x, y, w in times:
            graph[x].add((y, w))

        distances = self.dijkstra(k, n, graph)
        return max(distances) if -1 not in distances else -1