N = int(input())

nodes = []
for _ in range(N):
    val, left, right = map(int, input().split())
    nodes.append((val, left, right))

sums = [0] * (N + 1)

stack = [(0, 0)]  # (node index, x)

while stack:
    i, x = stack.pop()
    val, left, right = nodes[i]

    sums[x] += val

    if left != -1:
        stack.append((left, x - 1))
    if right != -1:
        stack.append((right, x + 1))

res = []

i = N
while sums[i] != 0:
    res.append(str(sums[i]))
    i -= 1
res.reverse()

i = 0
while sums[i] != 0:
    res.append(str(sums[i]))
    i += 1

print(" ".join(res))
