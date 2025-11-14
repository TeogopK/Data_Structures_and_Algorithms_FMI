class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if not root:
        return Node(val)
    
    if root.val < val:
        root.right = insert(root.right, val)
    else:
        root.left = insert(root.left, val)
        
    return root

def dfs(node):
    if not node:
        return 0
    
    if not node.left and not node.right and node.val % 2 == 1:
        return node.val
    
    return dfs(node.left) + dfs(node.right)

def leaves(root):
    print(dfs(root))

N = int(input())

root = None
for _ in range(N):
    root = insert(root, int(input()))

leaves(root)