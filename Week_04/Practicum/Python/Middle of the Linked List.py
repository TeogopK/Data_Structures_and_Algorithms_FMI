# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        slow = head
        fast = head
        while slow is not None and fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        return slow
        