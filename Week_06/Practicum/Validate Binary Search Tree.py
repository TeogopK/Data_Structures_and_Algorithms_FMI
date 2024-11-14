# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def valid_bst(current):
    if current is None:
        return True, int(1e12), -1 * int(1e12) # Some default value to return

    is_bst1, min1, max1 = valid_bst(current.left)
    is_bst2, min2, max2 = valid_bst(current.right)

    if not is_bst1 or not is_bst2:
        return False, -1, -1 # Will not be used either way
    
    if max1 >= current.val or min2 <= current.val:
        return False, -1, -1

    return True, min(min1, min2, current.val), max(max1, max2, current.val)

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return valid_bst(root)[0]
        