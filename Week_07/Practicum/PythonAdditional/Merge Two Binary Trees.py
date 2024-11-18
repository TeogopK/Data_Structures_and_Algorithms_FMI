# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(node1, node2):
    if not node1 and not node2:
        return None

    if not node2:
        node1.left = dfs(node1.left, None)
        node1.right = dfs(node1.right, None)
        return node1

    if not node1:
        node2.left = dfs(None, node2.left)
        node2.right = dfs(None, node2.right)
        return node2

    node1 = node1
    node1.val += node2.val
    node1.left = dfs(node1.left, node2.left)
    node1.right = dfs(node1.right, node2.right)

    return node1

class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        return dfs(root1, root2)