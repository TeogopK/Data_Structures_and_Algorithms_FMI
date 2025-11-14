# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(current):
    if current is None:
        return 0

    return 1 + max(dfs(current.left), dfs(current.right))

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return dfs(root)