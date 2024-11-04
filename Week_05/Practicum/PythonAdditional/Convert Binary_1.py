# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        result = 0
        lst = []
        while head:
            lst.append(head.val)
            head = head.next

        for i in range(len(lst)):
            
            result += lst[i] * (2 ** (len(lst) - 1 - i))
            print(i, result)

        return result
