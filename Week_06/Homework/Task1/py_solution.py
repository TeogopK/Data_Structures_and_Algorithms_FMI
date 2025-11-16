class Node:
    def __init__(self, val, left=-1, right=-1):
        self.val = val
        self.left = left  # indexes
        self.right = right


def dfs(node_index=0, X=0):
    if node_index != -1:
        if X < 0:
            sums_negative[X] += arr[node_index].val
        else:
            sums_positive[X] += arr[node_index].val

        dfs(arr[node_index].left, X - 1)
        dfs(arr[node_index].right, X + 1)


N = int(input())
arr = [Node(*map(int, input().split())) for _ in range(N)]

sums_negative = N * [0]
sums_positive = N * [0]

dfs()
output = (el for el in sums_negative + sums_positive if el > 0)
print(*output)
