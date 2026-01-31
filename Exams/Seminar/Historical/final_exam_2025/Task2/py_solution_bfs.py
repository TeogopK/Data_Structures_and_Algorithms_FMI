def isTree(current, parent, graph, visited):
    if current in visited:
        return False
    visited.add(current)

    for child in graph[current]:
        if child == parent:
            continue
        if not isTree(child, current, graph, visited):
            return False

    return True


def solve(graph, V, E):
    visited = set()

    if not isTree(0, -1, graph, visited):  # Root parent is -1
        return 0

    answer = 1 if len(visited) == V else 0
    return answer


Q = int(input())

for _ in range(Q):
    V, E = map(int, input().split())

    graph = {}
    for v in range(V):
        graph[v] = []

    for _ in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    answer = solve(graph, V, E)
    print(answer)
