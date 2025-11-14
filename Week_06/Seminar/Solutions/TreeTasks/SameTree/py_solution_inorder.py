# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(root, result):
        """Inorder Traversal"""
        if root:
            result.append(root.val)
            Solution.dfs(root.left, result)
            Solution.dfs(root.right, result)
        else:
            result.append(None)
        
        return result

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        left = Solution.dfs(p, [])
        right = Solution.dfs(q, [])

        return left == right