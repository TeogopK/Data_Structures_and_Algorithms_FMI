# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head or not head.next:
            return None

        size = 0
        current = head
        while current:
            size += 1
            current = current.next

        current = head
        for _ in range((size // 2) - 1):
            current = current.next

        current.next = current.next.next

        return head