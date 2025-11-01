import bisect

N, Q = map(int, input().split())

arr = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(Q)]

arr.sort()

for query in queries:
    left = bisect.bisect_left(arr, query[0])
    right = bisect.bisect_right(arr, query[1])    
    
    result = max(right - left, 0) # MaxLimit can be lower than MinLimit
    print(result)