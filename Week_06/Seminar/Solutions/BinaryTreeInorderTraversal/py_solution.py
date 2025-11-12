# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(current, lst):
    if current is None:
        return
    
    dfs(current.left, lst)
    lst.append(current.val)
    dfs(current.right, lst)

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        lst = []
        dfs(root, lst)
        return lst