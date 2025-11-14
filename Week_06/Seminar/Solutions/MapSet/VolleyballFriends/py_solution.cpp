m = int(input())
N = int(input())

s = set([m])

for _ in range(N) :
    x, y = map(int, input().split())

    if x in s :
s.add(y)

print(len(s))