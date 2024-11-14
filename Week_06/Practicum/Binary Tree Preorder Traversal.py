# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(node):
    if node is None:
        return []

    return [node.val] + dfs(node.left) + dfs(node.right)

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return dfs(root)