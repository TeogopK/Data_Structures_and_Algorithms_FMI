# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast_iter = slow_iter = head

        # Note that slow_iter != None check can be removed
        while fast_iter and fast_iter.next and slow_iter:
            slow_iter = slow_iter.next
            fast_iter = fast_iter.next.next

            if fast_iter == slow_iter:
                return True

        return False
