# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None

        if head.next == None:
            return head

        idx = 3

        last_odd = head
        last_even = first_even = head.next
        current = head.next.next

        while current != None:
            if idx % 2 == 1:
                last_odd.next = current
                current = current.next
                last_odd = last_odd.next
                last_odd.next = None
            else:
                last_even.next = current
                current = current.next
                last_even = last_even.next
                last_even.next = None

            idx += 1

        last_odd.next = first_even
        last_even.next = None

        return head
