# O(N * M + M * logM) time complexity
# O(M) space complexity


def solve(bills, payments):
    bills = bills.copy()

    # list.remove is a linear search for the first matching bill - O(M)
    for x in payments:
        bills.remove(x)

    bills.sort()
    return bills


M, N = map(int, input().split())
bills = [int(x) for x in input().split()]
payments = [int(x) for x in input().split()]

print(*solve(bills, payments))
