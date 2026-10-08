def solve(M, Q):
    count = 0
    for i in range(1, len(Q)):
        if Q[i] == Q[i - 1]:
            count += 1
    return count


N = int(input())
for _ in range(N):
    M, Q = input().split()
    M = int(M)
    res = solve(M, Q)
    print(res)
