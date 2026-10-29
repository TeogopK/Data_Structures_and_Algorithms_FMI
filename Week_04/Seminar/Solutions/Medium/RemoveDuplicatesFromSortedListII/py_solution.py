"""
We should handle:
- []
- [1]
- [1, 1]
- [1, 1, 1, 1, 1]
- [1, 2, 3, 4]
- [1, 1, 2, 3, 4]
- [1, 2, 3, 3, 3]
- [1, 1, 2, 3, 3, 4]
- [1, 2, 2, 2, 3, 3, 3]
- [1, 2, 2, 2, 3, 4, 4, 4]
- [1, 1, 2, 2, 3, 4]
- [1, 1, 1, 2, 2, 2]
...

"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode | None) -> ListNode | None:
        if not head:
            return None

        # X -> 1 -> 1 -> ...
        sentinel_head = ListNode(None, head) # must have value != allowed values

        prev, current = sentinel_head, head

        while current:
            if current.next and current.val == current.next.val: # we have two in a row
                group_value = current.val # save the value of the group

                while current and group_value == current.val:
                    # find the end of the group
                    current = current.next
                
                prev.next = current # skip the whole group via a big arrow from the prev to the next that is not the same - can be None as well

            else: # if we do not - move the previous to the current group
                prev = current
                current = current.next # and the current to the next potential group
        
        return sentinel_head.next

        