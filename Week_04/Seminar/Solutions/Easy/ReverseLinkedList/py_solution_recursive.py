# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        rest_of_the_list = head.next

        if not rest_of_the_list:
            return head

        new_head = self.reverseList(rest_of_the_list)

        rest_of_the_list.next = head
        head.next = None

        return new_head
