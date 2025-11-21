from collections import defaultdict

n = int(input())

d = defaultdict(int)

for _ in range(n):
    num = input()
    d[num] += 1
    
s = 0

for num, count in d.items():
    if count % 2 == 1:
        s += int(num) * count
        
print(s)