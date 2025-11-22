V = int(input())

tree = [[] for _ in range(V + 1)]
out = [0 for _ in range(V)]


def dfs(node, depth):
    if not node:
        return

    if not tree[node]:
        out[depth] += 1

    for child in tree[node]:
        dfs(child, depth + 1)


for _ in range(V - 1):
    parent, child = [int(x) for x in input().split()]
    tree[parent].append(child)

dfs(1, 0)

while out[-1] == 0:
    out.pop()

print(*out)
