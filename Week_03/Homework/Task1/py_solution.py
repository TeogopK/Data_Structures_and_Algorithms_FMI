def ternarySearch(key, l, r):

    if r > l:
        mid1 = l + (r - l) // 3
        mid2 = r - (r - l) // 3
        # print(key, mid1, mid2, l, r)

        if mid1 < key < mid2:
            return 1

        if key <= mid1:
            return 1 + ternarySearch(key, l, mid1)
        return 1 + ternarySearch(key, mid2, r)

    return 1


P, N = map(int, input().split())
queries = [int(input()) for _ in range(N)]

numbers = 3**P

for q in queries:
    result = ternarySearch(q, 1, numbers)
    print(result)
