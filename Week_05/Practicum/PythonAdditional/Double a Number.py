# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def double(current):
    if not current:
        return 0
    next_carry = double(current.next) 
    new_val = (current.val * 2) + next_carry
    carry = new_val // 10
    current.val = new_val % 10
    return carry

class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        carry = double(head)
        if carry:
            new_head = ListNode(1, head)
            return new_head
        return head