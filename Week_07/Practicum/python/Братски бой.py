from collections import defaultdict

n = int(input())

lst = input().split()

lst1 = lst[:n] # input().split()
lst2 = lst[n:] # input().split()

d = defaultdict(int)

count = 0

for x, y in zip(lst1, lst2):
    d[x] += 1
    if d[y] == 0:
        count += 1
    else:
        d[y] -= 1
        
print(count)