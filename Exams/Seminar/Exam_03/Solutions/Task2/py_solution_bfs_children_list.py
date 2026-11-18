# Контролно 3 СДА 2026/27, Задача 2 - отрицателните по нива (BFS, вход от конзолата)

# O(N) time complexity
# O(N) space complexity

from collections import deque


# tree[i] holds the children of node i
def print_negatives_by_level(values, tree):
    queue = deque([0])
    level = 0

    while queue:
        negatives = []

        # process exactly the nodes of the current level
        for _ in range(len(queue)):
            node = queue.popleft()

            if values[node] < 0:
                negatives.append(values[node])

            for child in tree[node]:
                queue.append(child)

        if negatives:
            print(f"Ниво {level}:", *negatives)

        level += 1


n, e = map(int, input().split())
values = list(map(int, input().split()))

tree = [[] for _ in range(n)]
for _ in range(e):
    parent, child = map(int, input().split())
    tree[parent].append(child)

print_negatives_by_level(values, tree)
