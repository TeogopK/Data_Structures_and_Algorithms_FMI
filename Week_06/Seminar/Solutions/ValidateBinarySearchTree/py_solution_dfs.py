# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, root, result):
        if root:
            self.inorder(root.left, result)
            result.append(root.val)
            self.inorder(root.right, result)

        return result

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        result = self.inorder(root, [])

        for i in range(1, len(result)):
            if result[i-1] >= result[i]:
                return False
        return True