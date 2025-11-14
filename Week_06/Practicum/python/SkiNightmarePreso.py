class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right

def dfs(tree, node, position, ans):
    if node == -1:
        return
    
    ans[int(position >= 0)][abs(position)] += tree[node].val
    dfs(tree, tree[node].left, position - 1, ans)
    dfs(tree, tree[node].right, position + 1, ans)
        
N = int(input())
tree = [Node(-1, -1, -1) for _ in range(N)] 
ans = ([0 for _ in range(N)], [0 for _ in range(N)])
  
for i in range(N):
    val, left, right = [int(x) for x in input().split()]
    tree[i] = Node(val, left, right)
    
dfs(tree, 0, 0, ans)

final_ans = list(reversed([x for x in ans[0] if x != 0])) + [x for x in ans[1] if x != 0]

print(*final_ans)