# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        current = head
        first_even = head.next

        last_odd = None

        i = 1
        while current.next:
            next_node = current.next

            current.next = current.next.next

            if current.next is None and i % 2 == 1:
                last_odd = current

            current = next_node
            i += 1

        last_odd = current if not last_odd else last_odd

        last_odd.next = first_even

        return head