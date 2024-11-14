# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def bfs(root):
    q = deque([root])
    
    ans = []

    while q:
        ans.append(q[-1].val)
        for _ in range(len(q)):
            current = q.popleft()
        
            if current.left:
                q.append(current.left)
            if current.right:
                q.append(current.right)
    
    return ans

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        return bfs(root) if root else []