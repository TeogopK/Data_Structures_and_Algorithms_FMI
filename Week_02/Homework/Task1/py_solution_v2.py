# Since ASCII Table is 0123...9 then ABC...Z finally abc...z with some other symbols in between

N = int(input())
s = input()

K = 256
counts = [0 for _ in range(K)]
digits, lower, upper = [], [], []

for c in s:
    counts[ord(c)] += 1

for i in range(ord("0"), ord("9") + 1):
    for _ in range(counts[i]):
        digits.append(chr(i))

for i in range(ord("a"), ord("z") + 1):
    for _ in range(counts[i]):
        lower.append(chr(i))

for i in range(ord("A"), ord("Z") + 1):
    for _ in range(counts[i]):
        upper.append(chr(i))

all = digits + lower + upper
output = "".join(all)

print(output)
