def can_produce_X_in_time(t, X, arr):
    """Can we produce the required amount of X beers in time t having all machines in arr?"""
    total = sum([max((t - Si), 0) // Ai for Ai, Si in arr])
    return total >= X


def binary_search(arr, X):
    left = 0
    right = (
        10**10
    )  # Worst is 10^4 waiting with A=10^3 for 1 beer for 10^9 beers - it will take 10^4 + 10^12. We need a bigger number.

    Xi = 0

    while left <= right:
        mid = left + (right - left) // 2

        if can_produce_X_in_time(mid, X, arr):
            right = mid - 1
            Xi = mid
        else:
            left = mid + 1

    return Xi


N, X = map(int, input().split())
arr = [tuple(map(int, input().split())) for _ in range(N)]

first_t = binary_search(arr, X)
print(first_t)
