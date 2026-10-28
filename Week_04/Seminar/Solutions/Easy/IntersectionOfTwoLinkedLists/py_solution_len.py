# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

"""Solution calculating the difference in lengths - O(N)."""


class Solution:
    def get_len(self, head):
        count = 0

        current = head
        while current:
            current = current.next
            count += 1

        return count

    def get_node(self, head, index):
        i = 0
        current = head

        while current and i < index:
            current = current.next
            i += 1

        return current

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        lenA = self.get_len(headA)
        lenB = self.get_len(headB)

        iterA = headA
        iterB = headB

        if lenA > lenB:
            iterA = self.get_node(headA, lenA - lenB)
        else:
            iterB = self.get_node(headB, lenB - lenA)

        while iterA and iterB:
            if iterA == iterB:
                return iterA

            iterA = iterA.next
            iterB = iterB.next

        return None
