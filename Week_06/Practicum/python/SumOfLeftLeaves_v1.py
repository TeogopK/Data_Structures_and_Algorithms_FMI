# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, current, results):
        if not current:
            return False

        if not current.left and not current.right:
            return True

        is_leaf = self.dfs(current.left, results)
        if is_leaf:
            results.append(current.left.val)
        self.dfs(current.right, results)

        return False

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        results = []
        self.dfs(root, results)
        return sum(results)
