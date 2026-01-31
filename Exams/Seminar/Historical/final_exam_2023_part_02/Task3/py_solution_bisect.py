from collections import defaultdict
from bisect import bisect_right

N = int(input())
products = [tuple(map(int, input().split())) for _ in range(N)]

Q = int(input())
queries = [int(input()) for _ in range(Q)]

sold = defaultdict(int)
maximum_id, maximum_count = -1, 0

answers = [-1] * N
times = [-1] * N

for i in range(N):
    product_id, time = products[i]
    
    sold[product_id] += 1
    times[i] = time

    if sold[product_id] >= maximum_count:
        maximum_id, maximum_count = product_id, sold[product_id]
    
    answers[i] = maximum_id

for time in queries:
    index = bisect_right(times, time)
    output = answers[index - 1] if index else -1
    
    print(output)