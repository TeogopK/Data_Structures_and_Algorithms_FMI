"""Solution using recursion"""

import sys

sys.setrecursionlimit(100_000)


class Node:
    def __init__(self, val=-1):
        self.val = val
        self.children = []

        self.time_in = -1
        self.time_out = -1


def dfs(indx=0):
    global time

    if indx == -1:
        return

    time += 1
    arr[indx].time_in = time

    for child in arr[indx].children:
        dfs(child)

    time += 1
    arr[indx].time_out = time


def is_parent(parent, child):
    return arr[parent].time_in < arr[child].time_in and arr[parent].time_out > arr[child].time_out


N = int(input())
arr = [Node() for _ in range(N)]

for _ in range(N - 1):
    parent, child = map(int, input().split())
    arr[parent].children.append(child)

Q = int(input())
queries = [list(map(int, input().split())) for _ in range(Q)]

time = 0
dfs()

for parent, child in queries:
    print("YES") if is_parent(parent, child) else print("NO")
