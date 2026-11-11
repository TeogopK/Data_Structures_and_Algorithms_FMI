# https://leetcode.com/problems/binary-tree-preorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, result):
        if root:
            result.append(root.val)
            self.dfs(root.left, result)
            self.dfs(root.right, result)

        return result

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return self.dfs(root, [])
