# Контролно 3 СДА 2026/27, Задача 1 - най-близка стойност в BST

# O(H) time complexity, where H is the height of the tree (O(N) in the worst case, O(logN) for a balanced tree)
# O(1) space complexity


class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def closestValue(root, target):
    closest = root.value
    node = root

    # in a BST we go down just like in a binary search - only one path is relevant
    while node:
        diff = abs(node.value - target)
        closest_diff = abs(closest - target)

        # on a tie we keep the smaller value
        if diff < closest_diff or (diff == closest_diff and node.value < closest):
            closest = node.value

        if target < node.value:
            node = node.left
        else:
            node = node.right

    return closest
