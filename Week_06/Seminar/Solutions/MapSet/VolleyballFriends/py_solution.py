# https://www.hackerrank.com/contests/sda-hw-8/challenges/volleyball-friends

m = int(input())
N = int(input())

s = set([m])

for _ in range(N):
    x, y = map(int, input().split())

    if x in s:
        s.add(y)

print(len(s))