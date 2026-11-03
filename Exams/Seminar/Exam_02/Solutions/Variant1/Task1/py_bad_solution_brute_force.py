# Контролно 2 СДА 2026/27, Вариант 1, Задача 1 - най-голямото k, за което k * k <= N

# O(sqrt(N)) time complexity
# O(1) space complexity


def solve(n):
    # Try every side k = 0, 1, 2, ... while the next square still fits
    k = 0
    while (k + 1) * (k + 1) <= n:
        k += 1

    return k


N = int(input())

print(solve(N))
