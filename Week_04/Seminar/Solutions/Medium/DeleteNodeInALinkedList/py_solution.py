# https://leetcode.com/problems/delete-node-in-a-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def deleteNode(self, node: ListNode) -> None:
        # no need to free the skipped node - the garbage collector does it
        node.val = node.next.val
        node.next = node.next.next
