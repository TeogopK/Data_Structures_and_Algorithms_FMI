"""Solution that works for input with unsorted products."""
from collections import defaultdict

N = int(input())
products = [tuple(map(int, input().split())) for _ in range(N)]

Q = int(input())
queries = [(int(input()), i) for i in range(Q)]

products.sort(key = lambda p: -p[1])
queries.sort(reverse = True)

sold = defaultdict(int)
maximum_id, maximum_count = -1, 0
output = [0] * Q

while queries:
    time, index = queries.pop()
    
    while products and products[-1][1] <= time:
        product_id, _ = products.pop()
        sold[product_id] += 1
        
        if sold[product_id] >= maximum_count:
            maximum_id, maximum_count = product_id, sold[product_id]
    
    output[index] = maximum_id

print(*output, sep = '\n')