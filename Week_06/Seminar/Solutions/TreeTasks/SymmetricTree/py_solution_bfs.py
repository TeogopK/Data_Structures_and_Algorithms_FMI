# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def check_symmetric(self, queue):
        d = deque(queue)

        while d:
            left = d.popleft()
            right = d.pop()

            if left and right:
                if left.val != right.val:
                    return False

            else:
                if left != right:
                    return False
        
        return True

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        q = deque([root.left, root.right])
        while q:
            if not self.check_symmetric(q):
                return False

            count = len(q)
            for i in range(count):
                current = q.popleft()

                if current:
                    q.append(current.left)
                    q.append(current.right)
                
        return True
       