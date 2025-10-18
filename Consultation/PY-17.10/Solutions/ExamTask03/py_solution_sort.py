N = int(input())
arr = [int(x) for x in input().split()]

arr2 = [(i, x) for i, x in enumerate(arr)]
arr2.sort(key=lambda x: x[1])

output = [-1 for i in range(N)]
for i, x in enumerate(arr2):
    output[x[0]] = i

print(*output)
