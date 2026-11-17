# Контролно 3 СДА 2026/27, Задача 2 - отрицателните по нива (BFS с Node, вход от конзолата)

# O(N) time complexity
# O(N) space complexity

from collections import deque


class Node:
    def __init__(self, value):
        self.value = value
        self.children = []


def print_negatives_by_level(root):
    queue = deque([root])
    level = 0

    while queue:
        negatives = []

        # process exactly the nodes of the current level
        for _ in range(len(queue)):
            node = queue.popleft()

            if node.value < 0:
                negatives.append(node.value)

            for child in node.children:
                queue.append(child)

        if negatives:
            print(f"Ниво {level}:", *negatives)

        level += 1


n, e = map(int, input().split())

# nodes[i] is the node with number i
nodes = [Node(value) for value in map(int, input().split())]
for _ in range(e):
    parent, child = map(int, input().split())
    nodes[parent].children.append(nodes[child])

print_negatives_by_level(nodes[0])
