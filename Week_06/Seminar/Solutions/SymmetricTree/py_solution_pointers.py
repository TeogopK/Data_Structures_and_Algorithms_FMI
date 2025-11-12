# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def check_opposite(self, L, R):
        if not L or not R:
            return L == R
        return L.val == R.val and self.check_opposite(L.left, R.right) and self.check_opposite(L.right, R.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        return self.check_opposite(root.left, root.right)