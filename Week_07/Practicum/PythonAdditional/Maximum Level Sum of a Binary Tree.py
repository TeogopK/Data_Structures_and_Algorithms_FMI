# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def bfs(root):
    q = deque([root])
    level = 1
    sum_ = -2 ** 31
    ans = 0

    while q:
        length = len(q)
        
        new_sum = sum([node.val for node in q])

        if new_sum > sum_:
            sum_ = new_sum
            ans = level

        for _ in range(length):
            current = q.popleft()

            if current.left:
                q.append(current.left)
            if current.right:
                q.append(current.right)

        level += 1

    return ans

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        return bfs(root)