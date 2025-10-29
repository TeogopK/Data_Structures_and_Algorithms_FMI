# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

"""Same idea as jumping over 1 square, but now jumping over two."""


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast_iter = slow_iter = head

        while fast_iter and fast_iter.next and fast_iter.next.next:
            slow_iter = slow_iter.next
            fast_iter = fast_iter.next.next.next

            if fast_iter == slow_iter:
                return True

        return False
