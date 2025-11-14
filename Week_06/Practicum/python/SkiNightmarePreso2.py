class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right

def dfs_max_left(tree, node, position):
    if node == -1:
        return position + 1
    
    return min(
        dfs_max_left(tree, tree[node].left, position - 1),
        dfs_max_left(tree, tree[node].right, position + 1)
    )
    
    
        
def dfs(tree, node, position, ans, min_left):
    if node == -1:
        return
    
    ans[position - min_left] += tree[node].val
    
    dfs(tree, tree[node].left, position - 1, ans, min_left)
    dfs(tree, tree[node].right, position + 1, ans, min_left)
        
N = int(input())
tree = [Node(-1, -1, -1) for _ in range(N)] 

  
for i in range(N):
    val, left, right = [int(x) for x in input().split()]
    tree[i] = Node(val, left, right)
    
min_left = dfs_max_left(tree, 0, 0)

ans = [0 for _ in range(N)]

dfs(tree, 0, 0, ans, min_left)

print(*[x for x in ans if x != 0])
    


