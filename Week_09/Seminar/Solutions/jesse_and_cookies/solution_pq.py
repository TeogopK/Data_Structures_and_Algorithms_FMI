from queue import PriorityQueue

N, K = map(int, input().split())

pq = PriorityQueue()
for el in map(int, input().split()):
    pq.put(el)

operations = 0

while not pq.empty() and pq.queue[0] < K:
    if pq.qsize() == 1:
        operations = -1
        break
    
    x, y = pq.get(), pq.get()
    pq.put(x + 2*y)
    operations += 1
    
print(operations)
