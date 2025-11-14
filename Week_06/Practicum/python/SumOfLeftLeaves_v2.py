# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, current, from_left=False):
        if not current:
            return 0

        if not current.left and not current.right and from_left:
            return current.val

        total = 0
        total += self.dfs(current.left, from_left=True)
        total += self.dfs(current.right, from_left=False)

        return total

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)
