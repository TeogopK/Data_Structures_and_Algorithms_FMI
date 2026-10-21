"""Here we just return the count. Solved in class"""

n, k = [int(x) for x in input().split()]
printers = [int(x) for x in input().split()]

l, r = 0, int(1e12)  # Some worst case right border


def papers_count(t):
    return sum([t // printer_speed for printer_speed in printers])  # O(K)


while l <= r:
    mid = (l + r) // 2

    if papers_count(mid) >= n:
        r = mid - 1
    else:
        l = mid + 1

print(l)
