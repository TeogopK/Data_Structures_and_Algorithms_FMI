# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        sums = defaultdict(int)
        sums[0] = 1

        def dfs(node, current_sum):
            # Prefix sum solution, a bit complex, but the goal is to propagate down the dfs
            # all possible active sums and that way we can easily gauge whether our current
            # node is part of a series which sum up to the target by ignoring those active sums.
            # Looking at the example 1, when we enter the node with value 1, our current sum will
            # be 18, but we know that some path above it already has sum 10 (the root), and that
            # we know that 1 is part of sum which sums to the target sum = 8
            if not node:
                return 0

            current_sum += node.val

            # Checks if we remove any of the previous sums will we reach the target
            count = sums[current_sum - targetSum]

            # Since we will propagate this downwards to the other dfs calls
            # we need to add to the count of the current sum. Basically "activating" the sum
            sums[current_sum] += 1

            count += dfs(node.left, current_sum) + dfs(node.right, current_sum)

            # After coming back from the recursion decrement the current sum count
            sums[current_sum] -= 1

            return count

        return dfs(root, 0)