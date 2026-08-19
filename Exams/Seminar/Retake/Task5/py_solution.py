# генерирано с claude
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


def populate(current, parent):
    if not current:
        return

    if current.left:
        parent[current.left] = current
        populate(current.left, parent)

    if current.right:
        parent[current.right] = current
        populate(current.right, parent)


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parent = {root: None}
        populate(root, parent)

        p_path = set()
        current = p
        while current:
            p_path.add(current)
            current = parent[current]

        current = q
        while current:
            if current in p_path:
                return current
            current = parent[current]

        return root
