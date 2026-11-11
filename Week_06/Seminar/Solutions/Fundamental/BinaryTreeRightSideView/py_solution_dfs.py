# https://leetcode.com/problems/binary-tree-right-side-view/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # DFS, който посещава първо дясното дете: първият възел, до който стигаме
    # на всяка дълбочина, е най-десният на това ниво.
    def dfs(self, root, depth, result):
        if not root:
            return

        if depth == len(result):
            result.append(root.val)

        self.dfs(root.right, depth + 1, result)
        self.dfs(root.left, depth + 1, result)

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.dfs(root, 0, result)
        return result
