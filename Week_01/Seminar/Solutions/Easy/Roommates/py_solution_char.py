Q = int(input())

for _ in range(Q):
    N, s = input().split()
    prev_c = None
    count = 0

    for c in s:
        if c == prev_c:
            count += 1

        prev_c = c

    print(count)
