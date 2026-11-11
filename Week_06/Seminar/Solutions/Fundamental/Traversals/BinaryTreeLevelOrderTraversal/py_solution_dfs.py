# https://leetcode.com/problems/binary-tree-level-order-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # DFS вместо BFS: подаваме дълбочината и добавяме всеки възел в result[depth].
    # Тъй като лявото дете се обхожда преди дясното, редът във всяко ниво е отляво надясно.
    def dfs(self, root, depth, result):
        if not root:
            return

        if depth == len(result):
            result.append([])
        result[depth].append(root.val)

        self.dfs(root.left, depth + 1, result)
        self.dfs(root.right, depth + 1, result)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        self.dfs(root, 0, result)
        return result
