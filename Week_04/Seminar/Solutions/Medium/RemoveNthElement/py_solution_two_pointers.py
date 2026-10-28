# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        start_prev = head
        iter = head
        length = 0

        # move iter n + 1 nodes ahead, so start_prev stops right before the node to remove
        while length <= n and iter:
            length += 1
            iter = iter.next

        # move both iter and start_prev until iter reaches the end
        while iter:
            iter = iter.next
            start_prev = start_prev.next
            length += 1

        # the n-th node from the end is the head
        if length == n:
            return head.next

        start_prev.next = start_prev.next.next

        return head
