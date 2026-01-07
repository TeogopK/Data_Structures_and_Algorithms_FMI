from collections import deque


class TreeNode:
    def __init__(self, value=None):
        self.children = []
        self.value = value


def is_leaf(current):
    if current is None:
        return False

    return len(current.children) == 0


def bfs(root):
    q = deque([root])
    counts = []

    while q:
        length = len(q)
        count = 0

        for _ in range(length):
            current = q.popleft()

            if is_leaf(current):
                count += 1

            for child in current.children:
                q.append(child)
        counts.append(count)
    return counts


V = int(input())
arr = [tuple(map(int, input().split())) for _ in range(V - 1)]
tree = [TreeNode() for _ in range(V + 1)]  # Since we count from 0

for parent, child in arr:
    tree[parent].children.append(tree[child])

counts = bfs(tree[1])
print(*counts)
