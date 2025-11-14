# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        output = []
        stack = []
        current = root

        while stack or current:
            if current:
                stack.append(current) 
                current = current.left
            else:
                current = stack.pop()
                output.append(current.val)
                current = current.right

        return output
