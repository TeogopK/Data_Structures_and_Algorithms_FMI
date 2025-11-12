# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def symmetric_tree_dfs(first_tree, second_tree):
    if first_tree is None and second_tree is None:
        return True
    
    if first_tree is None or second_tree is None or first_tree.val != second_tree.val:
        return 0

    return (symmetric_tree_dfs(first_tree.left, second_tree.right) and symmetric_tree_dfs(first_tree.right, second_tree.left))

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        return symmetric_tree_dfs(root.left, root.right)
        