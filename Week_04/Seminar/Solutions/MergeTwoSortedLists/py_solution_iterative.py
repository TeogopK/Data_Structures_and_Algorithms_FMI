# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2

        if not list2:
            return list1

        merged_head = ListNode()
        if list1.val <= list2.val:
            merged_head = list1
            list1 = list1.next
        else:
            merged_head = list2
            list2 = list2.next

        merged_iter = merged_head
        while list1 and list2:
            if list1.val <= list2.val:
                merged_iter.next = list1
                list1 = list1.next
            else:
                merged_iter.next = list2
                list2 = list2.next
            merged_iter = merged_iter.next

        if list1:
            merged_iter.next = list1

        if list2:
            merged_iter.next = list2

        return merged_head
