from collections import defaultdict

n = int(input())

d = defaultdict(int)

for _ in range(n):
    n = int(input())
    d[n] += 1
    d[n] %= 10
    
print(len([x for x in d if d[x] != 0]), sum([d[x] for x in d if d[x] != 0]))