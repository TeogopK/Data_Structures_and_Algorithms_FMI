# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from queue import Queue

def bfs(root):
    return_lst = []
    q = Queue()
    q.put(root)

    while not q.empty():
        q_copy = Queue()
        lst = []
        while not q.empty():
            front = q.get()
            
            if front.left is not None:
                q_copy.put(front.left)
            if front.right is not None:
                q_copy.put(front.right)
            
            lst.append(front.val)
        
        q = q_copy
        return_lst.append(lst)

    return return_lst

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        return bfs(root)