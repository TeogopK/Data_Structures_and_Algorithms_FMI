from collections import defaultdict

n = int(input())

lst = []
d = defaultdict(int)

for _ in range(n):
    s = input()
    lst.append(s)
    d[s] += 1
    
print(*[d[s] for s in lst])