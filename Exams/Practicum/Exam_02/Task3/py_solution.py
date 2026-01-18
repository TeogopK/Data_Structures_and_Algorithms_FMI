def find(x, parents):
    if parents[x] == x:
        return x

    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent


def union(x, y, parents):
    x_root = find(x, parents)
    y_root = find(y, parents)

    parents[x_root] = y_root


V, E = [int(x) for x in input().split()]
par = [i for i in range(V + 1)]

for _ in range(E):
    u, v = [int(x) for x in input().split()]
    union(u, v, par)

Q = int(input())

ans = []

for _ in range(Q):
    tp, u, v = [int(x) for x in input().split()]

    if tp == 1:
        query_answer = find(u, par) == find(v, par)
        ans.append("1" if query_answer else "0")
    elif tp == 2:
        union(u, v, par)

print("".join(ans))
