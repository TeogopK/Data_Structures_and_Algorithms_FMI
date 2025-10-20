N = int(input())
arr = [int(x) for x in input().split()]
arr_indexes = [(i, x) for i, x in enumerate(arr)]

arr_indexes.sort(key=lambda x: x[1])

results = [-1 for _ in range(N)]

for i, el in enumerate(arr_indexes):
    results[el[0]] = i

print(*results)
