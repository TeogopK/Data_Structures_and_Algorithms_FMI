# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def search(current, val):
    if current is None or current.val == val:
        return current

    if val < current.val:
        return search(current.left, val)

    return search(current.right, val)

class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        return search(root, val)