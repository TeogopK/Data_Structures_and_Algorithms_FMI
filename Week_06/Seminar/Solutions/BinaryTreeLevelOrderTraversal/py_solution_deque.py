# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return None
        
        result = []
        q = deque([root])

        while q:
            count = len(q)
            level_nums = []

            for _ in range(count):
                current = q.popleft()
                level_nums.append(current.val)

                if current.left:
                    q.append(current.left)
                if current.right:
                    q.append(current.right)
            
            result.append(level_nums)

        return result
                