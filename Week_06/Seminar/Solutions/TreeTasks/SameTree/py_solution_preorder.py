# https://leetcode.com/problems/same-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorder(self, root, result):
        if root:
            result.append(root.val)
            self.preorder(root.left, result)
            self.preorder(root.right, result)
        else:
            # Без None дърветата [1, 2] (2 вляво) и [1, null, 2] (2 вдясно) дават един и същ списък
            result.append(None)

        return result

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return self.preorder(p, []) == self.preorder(q, [])
