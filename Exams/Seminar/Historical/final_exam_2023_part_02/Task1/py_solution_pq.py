from queue import PriorityQueue

def solve():
    chairs = PriorityQueue()
    for x in range(N):
        chairs.put(x)

    current_times = PriorityQueue()

    while times:
        start, end, index = times.get()

        while not current_times.empty() and start > current_times.queue[0][0]:
            _, freed_chair = current_times.get()
            chairs.put(freed_chair)

        chair = chairs.get()
        current_times.put((end, chair))

        if T == index:
            return chair
    
    return -1

N = int(input())

times = PriorityQueue()
for i in range(N):
    start, end = map(int, input().split())
    times.put((start, end, i))

T = int(input())
       
print(solve())