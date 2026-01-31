def find(x, parents):
    if parents[x[0]][0] == x[0]:
        return parents[x[0]]

    parent_tuple = find(parents[x[0]], parents)
    parents[x[0]] = parent_tuple

    return parent_tuple


def union(x, y, parents, weight):
    x_parent = find(x, parents)
    y_parent = find(y, parents)

    parents[x_parent[0]][0] = y_parent[0]
    parents[x_parent[0]][1] = max(x_parent[1], y_parent[1], weight)
    parents[y_parent[0]][1] = max(x_parent[1], y_parent[1], weight)


V, E, K = map(int, input().split())

edges = [list(map(int, input().split())) for _ in range(E)]
edges.sort(key=lambda value: value[2])

parents = [[v, 0] for v in range(V)]  # vertex -> parent vertex, max edge
clusters = V

for edge in edges:
    if clusters == K:
        break
    x, y, w = edge

    x_parent = find(parents[x], parents)
    y_parent = find(parents[y], parents)

    if x_parent[0] == y_parent[0]:
        continue

    union(x_parent, y_parent, parents, w)
    clusters -= 1


for v in range(V):
    find([v, 0], parents)

answer = list(sorted(set(value[1] for value in parents)))
answer = (K - len(answer)) * [0] + answer
print(*answer)
