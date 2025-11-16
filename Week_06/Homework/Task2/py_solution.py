class Node:
    def __init__(self, left=-1, right=-1):
        self.left = left
        self.right = right

        self.count_left = 0
        self.count_right = 0


def dfs(i=0):
    if i != -1:
        r = arr[i].left
        l = arr[i].right

        dfs(l)
        dfs(r)

        arr[i].count_left = 1 + arr[l].count_left + arr[l].count_right if l != -1 else 0
        arr[i].count_right = 1 + arr[r].count_left + arr[r].count_right if r != -1 else 0


N = int(input())
arr = [Node(*map(int, input().split())) for _ in range(N)]

dfs()
max_remove = 0

for i in range(N):
    l, r = arr[i].count_left, arr[i].count_right
    counts = l, r, N - (l + r + 1)

    temp_remove = 1

    for count in counts:
        if count:
            temp_remove *= count

    max_remove = max(temp_remove, max_remove)

print(max_remove)
