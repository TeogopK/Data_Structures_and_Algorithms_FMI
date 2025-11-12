# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root, level = 0):
        if not root:
            return level
        
        L = self.dfs(root.left, level + 1)
        R = self.dfs(root.right, level + 1)

        return max(L, R)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)