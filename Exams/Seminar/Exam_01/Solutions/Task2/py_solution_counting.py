# O(M + N + K) time complexity
# O(K) space complexity, where K = 1000 is the max amount (O(M + N) if we count the input lists)

MAX_AMOUNT = 1000


def solve(bills, payments):
    # counts[x] - how many unpaid bills with amount x there are
    counts = [0] * (MAX_AMOUNT + 1)

    for x in bills:
        counts[x] += 1

    for x in payments:
        counts[x] -= 1

    # Iterating the amounts in ascending order gives sorted output
    unpaid = []
    for amount in range(1, MAX_AMOUNT + 1):
        unpaid.extend([amount] * counts[amount])

    return unpaid


M, N = map(int, input().split())
bills = [int(x) for x in input().split()]
payments = [int(x) for x in input().split()]

print(*solve(bills, payments))
