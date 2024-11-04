# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:

        while head is not None and head.val == val:
            head = head.next

        if head is None:
            return None        

        prev = head
        current = head.next

        while current is not None:
            if current.val == val:
                prev.next = current.next
            else:
                prev = current

            current = current.next

        return head