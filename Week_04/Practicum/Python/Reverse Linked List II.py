# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head is None:
            return None
        if head.next is None:
            return head

        curr = head
        last_of_left_third = None
        idx = 1

        while idx < left:
            last_of_left_third = curr
            curr = curr.next
            idx += 1

        first_of_sorted_third = curr
        prev = None

        while idx <= right:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            idx += 1

        if last_of_left_third:
            last_of_left_third.next = prev
        else:
            head = prev

        first_of_sorted_third.next = curr
        return head
