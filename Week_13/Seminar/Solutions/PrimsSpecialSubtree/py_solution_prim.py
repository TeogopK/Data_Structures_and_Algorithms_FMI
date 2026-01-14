from heapq import heappush, heappop

def prim(start, V, graph):
    visited = set()
    pq = [(0, start)]
    mst_weight = 0
    
    while len(visited) != V:
        current_weight, current = heappop(pq)
        
        if current in visited:
            continue
        
        visited.add(current)
        mst_weight += current_weight
        
        for neighb, weight in graph[current]:
            if neighb in visited:
                continue
                            
            heappush(pq, (weight, neighb))
    
    return mst_weight
    
N, M = map(int, input().split())
graph = {v: set() for v in range(1, N + 1)}

for _ in range(M):
    x, y, w = map(int, input().split())
    graph[x].add((y, w))
    graph[y].add((x, w))
    
start = int(input())
mst_weight = prim(start, N, graph)
print(mst_weight)