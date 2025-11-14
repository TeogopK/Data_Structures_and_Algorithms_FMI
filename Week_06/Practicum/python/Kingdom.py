class Node:
    def __init__(self):
        self.children = []

def dfs(tree, node, ans):
    if not tree[node].children:
        return 1
    
    number_ancestors = 0
    for child in tree[node].children:
        number_ancestors += dfs(tree, child, ans)
        
    ans[node] = number_ancestors
    return 1 + number_ancestors 

N = int(input())

tree = [Node() for _ in range(N)]
ans = [0 for _ in range(N)]

for i in range(N):
    try:
        parent, child = [int(x) for x in input().split()]
        tree[parent].children.append(child)
    except EOFError:
        break

dfs(tree, 0, ans)

print(*ans)

