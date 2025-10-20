# Try not to use dict on exams/homeworks for now!

from collections import defaultdict

s = input()

d = defaultdict(int)

for c in s:
    d[c] += 1

for i, c in enumerate(s):
    if d[c] == 1:
        print(i, end=" ")
