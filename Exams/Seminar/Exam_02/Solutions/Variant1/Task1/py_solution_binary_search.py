# Контролно 2 СДА 2026/27, Вариант 1, Задача 1 - най-голямото k, за което k * k <= N

# O(logN) time complexity
# O(1) space complexity


def solve(n):
    # k * k is increasing, so we binary search for the last k in [0, N] with k * k <= N
    left, right = 0, n
    answer = 0

    while left <= right:
        mid = (left + right) // 2

        if mid * mid <= n:
            # mid fits - remember it and look for a bigger side
            answer = mid
            left = mid + 1
        else:
            right = mid - 1

    return answer


N = int(input())

print(solve(N))
