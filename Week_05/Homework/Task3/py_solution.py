N = int(input())
arr = [int(input()) for _ in range(N)]

d = []

for el in arr:
    if el < 0:
        is_gone = False

        while not is_gone and d and d[-1] > 0:
            if abs(el) > d[-1]:
                d.pop()
            elif abs(el) < d[-1]:
                is_gone = True
            else:
                d.pop()
                is_gone = True

        if not is_gone:
            d.append(el)
    else:
        d.append(el)

print(*d)
