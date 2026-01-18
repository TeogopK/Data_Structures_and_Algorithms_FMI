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


V, E, S = [int(x) for x in input().split()]
par = [i for i in range(V)]

for _ in range(E):
    u, v = [int(x) for x in input().split()]
    union(u, v, par)

Q = int(input())

for _ in range(Q):
    u = int(input())

    print("YES" if find(u, par) == find(S, par) else "NO")
