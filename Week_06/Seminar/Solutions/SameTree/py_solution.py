# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def same_tree_dfs(first_tree, second_tree):
    if first_tree is None and second_tree is None:
        return True
    
    if first_tree is None or second_tree is None or first_tree.val != second_tree.val:
        return False

    return (same_tree_dfs(first_tree.left, second_tree.left) and same_tree_dfs(first_tree.right, second_tree.right))

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return same_tree_dfs(p, q)