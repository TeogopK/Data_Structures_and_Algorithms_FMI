# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        size = 0
        current = head
        while current != None:
            size += 1
            current = current.next

        target = size // 2

        current = head
        for _ in range(target):
            current = current.next

        return current
