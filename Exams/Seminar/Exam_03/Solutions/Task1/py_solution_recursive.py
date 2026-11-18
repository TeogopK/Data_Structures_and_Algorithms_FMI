# Контролно 3 СДА 2026/27, Задача 1 - най-близка стойност в BST

# O(H) time complexity, where H is the height of the tree (O(N) in the worst case, O(logN) for a balanced tree)
# O(H) space complexity for the recursion stack


class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def closest_from(node, target, closest):
    if not node:
        return closest

    diff = abs(node.value - target)
    closest_diff = abs(closest - target)

    # on a tie we keep the smaller value
    if diff < closest_diff or (diff == closest_diff and node.value < closest):
        closest = node.value

    # in a BST only one of the subtrees can contain a closer value
    if target < node.value:
        return closest_from(node.left, target, closest)

    return closest_from(node.right, target, closest)


def closestValue(root, target):
    return closest_from(root, target, root.value)
