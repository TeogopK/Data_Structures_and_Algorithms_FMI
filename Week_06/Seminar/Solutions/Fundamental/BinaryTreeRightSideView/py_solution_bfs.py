# https://leetcode.com/problems/binary-tree-right-side-view/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        result = []
        q = deque([root])
        while q:
            level_size = len(q)
            for i in range(level_size):
                current = q.popleft()
                # последният възел в нивото е видим отдясно
                if i == level_size - 1:
                    result.append(current.val)
                if current.left:
                    q.append(current.left)
                if current.right:
                    q.append(current.right)

        return result
