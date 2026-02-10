from collections import defaultdict

N = int(input())
d = defaultdict(int)

for _ in range(N):
    """Saving space and time by not reading all strings at once..."""
    c = input()
    d[c] += 1

total = 0
for count in d.values():
    total += count // 3

print(total)
