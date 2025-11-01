def binary_search_lower_bound(arr, X):
    left = 0
    right = len(arr) - 1

    Xi = len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if X <= arr[mid]:
            right = mid - 1
            Xi = mid
        else:
            left = mid + 1

    return Xi


def binary_search_upper_bound(arr, X):
    left = 0
    right = len(arr) - 1

    Xi = len(arr)

    while left <= right:
        mid = left + (right - left) // 2

        if X < arr[mid]:
            right = mid - 1
            Xi = mid
        else:
            left = mid + 1

    return Xi


N, Q = map(int, input().split())

arr = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(Q)]

arr.sort()

for query in queries:
    left = binary_search_lower_bound(arr, query[0])
    right = binary_search_upper_bound(arr, query[1])

    result = max(right - left, 0)  # MaxLimit can be lower than MinLimit
    print(result)
