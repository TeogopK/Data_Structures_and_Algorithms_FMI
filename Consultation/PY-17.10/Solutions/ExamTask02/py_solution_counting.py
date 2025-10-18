s = input()

K = 256
counts = [0 for _ in range(K)]

for c in s:
    counts[ord(c)] += 1

for i, c in enumerate(s):
    if counts[ord(c)] == 1:
        print(i, end=" ")
