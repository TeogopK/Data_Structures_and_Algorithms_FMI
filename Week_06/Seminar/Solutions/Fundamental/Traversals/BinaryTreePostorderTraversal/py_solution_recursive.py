# https://leetcode.com/problems/binary-tree-postorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, result):
        if root:
            self.dfs(root.left, result)
            self.dfs(root.right, result)
            result.append(root.val)

        return result

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return self.dfs(root, [])
