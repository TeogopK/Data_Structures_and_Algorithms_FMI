N = int(input())
arr = [int(x) for x in input().split()]

current_arr, results = [], []

for i, x in enumerate(arr):
    current_arr.append(x)
    current_arr.sort()

    left_med, right_med = current_arr[i // 2], current_arr[(i + 1) // 2]
    results.append((left_med + right_med) / 2)

results = [int(x) if x == int(x) else x for x in results]  # Filtering (1 + 3) / 2 = 2.0
print(*results, sep="\n")
