# https://leetcode.com/problems/range-sum-of-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque


class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        total = 0
        q = deque([root])
        while q:
            current = q.popleft()
            if not current:
                continue

            # Използваме свойството на BST, за да не обхождаме поддървета извън интервала
            if current.val < low:
                q.append(current.right)
            elif current.val > high:
                q.append(current.left)
            else:
                total += current.val
                q.append(current.left)
                q.append(current.right)

        return total
