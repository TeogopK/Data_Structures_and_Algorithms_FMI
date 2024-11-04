# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def reverse(prev, curr):
    if curr.next is None:
        curr.next = prev
        return curr

    head = reverse(curr, curr.next)
    curr.next = prev

    return head

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        return reverse(None, head)