N = int(input())

arr = [int(x) for x in input().split()]

K = max(arr) + 1

counts = [0 for _ in range(K)]
output = [-1 for _ in range(N)]

for x in arr:
    counts[x] += 1

for i in range(1, len(counts)):
    counts[i] += counts[i - 1]

for i in reversed(range(N)):
    output[i] = counts[arr[i]] - 1
    counts[arr[i]] -= 1

print(*output)
