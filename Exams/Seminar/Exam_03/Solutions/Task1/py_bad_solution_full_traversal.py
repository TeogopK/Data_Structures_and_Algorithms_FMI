# Контролно 3 СДА 2026/27, Задача 1 - най-близка стойност в BST

# O(N) time complexity - we visit every node, although the BST order is not used
# O(H) space complexity for the recursion stack, where H is the height of the tree


class TreeNode:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def visit(node, target, closest):
    if not node:
        return closest

    diff = abs(node.value - target)
    closest_diff = abs(closest - target)

    # on a tie we keep the smaller value
    if diff < closest_diff or (diff == closest_diff and node.value < closest):
        closest = node.value

    closest = visit(node.left, target, closest)
    closest = visit(node.right, target, closest)

    return closest


def closestValue(root, target):
    return visit(root, target, root.value)
