# https://leetcode.com/problems/delete-node-in-a-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        # В Python няма указател към указател, затова пазим родителя
        parent = None
        current = root
        while current and current.val != key:
            parent = current
            current = current.left if key < current.val else current.right

        if not current:
            return root

        if current.left and current.right:
            # 2 деца: най-малкият node в дясното поддърво заема мястото на current
            min_parent = current
            min_node = current.right
            while min_node.left:
                min_parent = min_node
                min_node = min_node.left

            # Изключваме min_node от старата му позиция
            # Той може да има само дясно дете (не може да има ляво, защото е минимален)
            if min_parent is current:
                min_parent.right = min_node.right
            else:
                min_parent.left = min_node.right

            # Свързваме заместващия node с децата на изтрития node
            min_node.left = current.left
            min_node.right = current.right
            replacement = min_node
        else:
            # 0 или 1 дете: заместваме с детето (или с None)
            replacement = current.left or current.right

        # Пренасочваме връзката от родителя (или корена) към заместващия node
        if not parent:
            return replacement
        if parent.left is current:
            parent.left = replacement
        else:
            parent.right = replacement

        return root
