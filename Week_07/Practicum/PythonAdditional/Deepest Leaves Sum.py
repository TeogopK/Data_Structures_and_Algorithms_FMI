# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def bfs(root):
    q = deque([root])
    

    while q:
        length = len(q)
        
        ans = [node.val for node in q]
        for _ in range(length):
            current = q.popleft()

            if current.left:
                q.append(current.left)
            if current.right:
                q.append(current.right)

    return sum(ans)

class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        return bfs(root)