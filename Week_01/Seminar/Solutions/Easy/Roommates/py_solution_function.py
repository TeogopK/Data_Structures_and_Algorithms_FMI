# https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/1-410

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
