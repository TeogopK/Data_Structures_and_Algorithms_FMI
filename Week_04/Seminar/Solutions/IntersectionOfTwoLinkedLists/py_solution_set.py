# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

"""Solution using extra memory for set."""


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        marked = set()

        current = headA
        while current:
            marked.add(current)
            current = current.next

        current = headB
        while current and current not in marked:
            current = current.next

        return current
