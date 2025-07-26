"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:

    def merge(self, curr):
        child = curr.child

        while child.next is not None:
            child = child.next
        
        if curr.next is not None:
            child.next = curr.next
            curr.next.prev = child

        curr.next = curr.child
        curr.child.prev = curr
        curr.child = None

    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        curr = head

        while curr is not None:
            if curr.child is not None:
                self.merge(curr)
            curr = curr.next
        
        return head

        