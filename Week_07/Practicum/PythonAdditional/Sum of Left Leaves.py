# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(node, is_left):
    if node is None:
        return 0

    if node.left is None and node.right is None and is_left:
        return node.val

    return dfs(node.left, True) + dfs(node.right, False)

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        return dfs(root, False)

        