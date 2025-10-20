N = int(input())
arr = [int(x) for x in input().split()]
counts = [[] for _ in range(max(arr) + 1)]

for i, x in enumerate(arr):
    counts[x].append(i)

output = [-1 for _ in range(N)]
count = 0

for lst in counts:
    for index in lst:
        output[index] = count
        count += 1

print(*output)
