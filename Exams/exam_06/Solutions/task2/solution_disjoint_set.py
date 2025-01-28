def find(x):
    if x == parent[x]:
        return x

    root = find(parent[x])
    parent[x] = root
    return root


def union_(x, y):
    root_x = find(x)
    root_y = find(y)

    parent[root_x] = root_y


v, e = map(int, input().split())

edges = []
parent = [i for i in range(v + 1)]
for _ in range(e):
    x, y, w = map(int, input().split())
    edges.append((x, y, w))

edges.sort(key=lambda el: -el[2])
val = 0
comps = v

for x, y, w in edges:
    if not (find(x) == find(y)):
        union_(x, y)
        val += w
        comps -= 1
    if comps == 0:
        break
print(f"{comps} {val}")
