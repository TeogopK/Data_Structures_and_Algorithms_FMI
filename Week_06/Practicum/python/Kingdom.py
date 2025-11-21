def dfs(tree, node, ans):
    if not tree[node]:
        return 1
    
    number_ancestors = 0
    for child in tree[node]:
        number_ancestors += dfs(tree, child, ans)
        
    ans[node] = number_ancestors
    return 1 + number_ancestors 

N = int(input())

tree = [[] for _ in range(N)]
ans = [0 for _ in range(N)]

for i in range(N - 1):
    parent, child = [int(x) for x in input().split()]
    tree[parent].append(child)

dfs(tree, 0, ans)

print(*ans)