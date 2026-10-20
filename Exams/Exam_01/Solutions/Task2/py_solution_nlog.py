# O(M * logM + N * logN) time complexity
# O(M + N) space complexity


def solve(bills, payments):
    bills = sorted(bills)
    payments = sorted(payments)
    unpaid = []

    # Two pointers - every payment has a matching bill, so when both lists are sorted
    # the current payment is either equal to the current bill (paid) or bigger (bill stays unpaid)
    j = 0
    for x in bills:
        if j < len(payments) and x == payments[j]:
            j += 1
        else:
            unpaid.append(x)

    return unpaid


M, N = map(int, input().split())
bills = [int(x) for x in input().split()]
payments = [int(x) for x in input().split()]

print(*solve(bills, payments))
