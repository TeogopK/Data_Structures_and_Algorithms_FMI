import heapq

N, K = map(int, input().split())
h = list(map(int, input().split()))

heapq.heapify(h)

operations = 0

while h and h[0] < K:
    if len(h) == 1:
        operations = -1
        break
    
    x, y = heapq.heappop(h), heapq.heappop(h)
    heapq.heappush(h, x + 2*y)
    operations += 1
    
print(operations)
