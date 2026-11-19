# https://www.hackerrank.com/contests/sda-2021-2022-test-7-final/challenges/challenge-1770/problem

n = int(input())
numbers = list(map(int, input().split()))

counts = {}

for x in numbers:
    counts[x] = counts.get(x, 0) + 1

unique = []
duplicates = []
seen = set()

# The order comes from the input list, not from the dict
for x in numbers:
    if counts[x] == 1:
        unique.append(x)
    elif x not in seen:
        seen.add(x)
        duplicates.append(x)

print(*unique, *duplicates)
