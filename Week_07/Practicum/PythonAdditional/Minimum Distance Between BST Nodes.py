# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

prev = -2 ** 31
min_ = 2 ** 31

def dfs(node):
    if node is None:
        return

    global prev
    global min_

    dfs(node.left)
    min_ = min(min_, node.val - prev)
    prev = node.val
    dfs(node.right)


class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        global min_
        global prev
        prev = -2 ** 31
        min_ = 2 ** 31

        dfs(root)
        
        return min_