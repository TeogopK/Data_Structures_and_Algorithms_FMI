# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, root, low, high):
        if not root:
            return True
        
        if not low < root.val < high:
            return False
        
        return self.inorder(root.left, low, root.val) and self.inorder(root.right, root.val, high)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        high = 1 << 32 # by constraints
        low = -high

        return self.inorder(root, low, high)
