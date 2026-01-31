import heapq

def solve():
    heapq.heapify(times)
    chairs = [num for num in range(N)]
    heapq.heapify(chairs)

    current_times = []

    while times:
        start, end, index = heapq.heappop(times)

        while current_times and start > current_times[0][0]:
            _, freed_chair = heapq.heappop(current_times)
            heapq.heappush(chairs, freed_chair)

        chair = heapq.heappop(chairs)
        heapq.heappush(current_times, (end, chair))

        if T == index:
            return chair
    
    return -1

N = int(input())

times = [tuple(map(int, input().split())) + tuple([i]) for i in range(N)]
T = int(input())

print(solve())