# генерирано с claude
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def splitCircularLinkedList(self, list: ListNode) -> List[ListNode]:
        slow = list
        fast = list

        while fast.next is not list and fast.next.next is not list:
            slow = slow.next
            fast = fast.next.next

        second_list = slow.next

        if fast.next is list:
            fast.next = second_list
        else:
            fast.next.next = second_list

        slow.next = list

        return [list, second_list]
